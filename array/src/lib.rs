use std::alloc;
use std::ptr::NonNull;

pub struct Array<T> {
    ptr: NonNull<T>,
    len: usize,
    capacity: usize,
}

impl<T> Array<T> {
    pub fn new() -> Self {
        Self {
            ptr: NonNull::dangling(),
            len: 0,
            capacity: 0,
        }
    }

    pub fn push(&mut self, elem: T) {
        assert_ne!(std::mem::size_of::<T>(), 0, "No zero sized types");

        if self.capacity == 0 {
            let layout = alloc::Layout::array::<T>(4)
                .expect("overflow happened could not allocate the array");

            // SAFETY: the layout is hardcoded to be 4 * size_of<T> and
            // SAFETY: size_of<T> is > 0
            let ptr = unsafe { alloc::alloc(layout) } as *mut T;
            let ptr =
                NonNull::new(ptr).expect("alloc returned null ptr, could not allocate memory");

            // SAFETY: ptr is non-null and we have just allocated enough space for this item.
            unsafe { ptr.as_ptr().write(elem) };

            self.ptr = ptr;
            self.len = 1;
            self.capacity = 4;
        } else if self.len < self.capacity {
            let offset = self
                .len
                .checked_mul(std::mem::size_of::<T>())
                .expect("cannot reach memory location");
            assert!(offset < isize::MAX as usize, "Wrapped isize");

            // SAFETY: offset cannot wrap around and pointer is pointing to valid memory
            // SAFETY: and writing to an offset at self.len is valid
            unsafe {
                self.ptr.as_ptr().add(self.len).write(elem);
            }
            self.len += 1;
        } else {
            debug_assert!(self.len == self.capacity);

            let new_capacity = self.capacity.checked_mul(2).expect("capacity wrapped");
            let align = std::mem::align_of::<T>();
            let size = std::mem::size_of::<T>() * self.capacity;
            size.checked_add(size % align).expect("can't allocate");
            let ptr = unsafe {
                let layout = alloc::Layout::from_size_align_unchecked(size, align);
                let ptr = alloc::realloc(
                    self.ptr.as_ptr() as *mut u8,
                    layout,
                    std::mem::size_of::<T>() * new_capacity,
                ) as *mut T;
                let ptr = NonNull::new(ptr)
                    .expect("realloc returned null ptr, could not reallocate memory");

                ptr.add(self.len).write(elem);

                ptr
            };

            self.ptr = ptr;
            self.len += 1;
            self.capacity = new_capacity;
        }
    }

    pub fn len(&self) -> usize {
        self.len
    }

    pub fn capacity(&self) -> usize {
        self.capacity
    }
}

impl<T> Drop for Array<T> {
    fn drop(&mut self) {
        unsafe {
            std::ptr::drop_in_place(std::slice::from_raw_parts_mut(self.ptr.as_ptr(), self.len));
            let layout = alloc::Layout::array::<T>(self.capacity).unwrap();
            alloc::dealloc(self.ptr.as_ptr() as *mut u8, layout);
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let mut arr = Array::new();
        arr.push(10);
        arr.push(20);
        arr.push(30);
        arr.push(40);
        arr.push(50);
        arr.push(60);
        arr.push(70);
        arr.push(80);
        arr.push(90);

        assert_eq!(arr.len(), 9);
        assert_eq!(arr.capacity(), 16);
    }
}
