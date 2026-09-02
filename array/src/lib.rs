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
        }
    }

    pub fn len(&self) -> usize {
        self.len
    }

    pub fn capacity(&self) -> usize {
        self.capacity
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let arr = Array::<usize>::new();

        assert_eq!(arr.len(), 0);
        assert_eq!(arr.capacity(), 0);
    }
}
