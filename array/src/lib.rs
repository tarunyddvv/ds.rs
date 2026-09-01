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
