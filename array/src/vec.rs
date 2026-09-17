#![allow(unused)]

use std::ptr::NonNull;

pub struct Vec<T> {
    ptr: NonNull<T>,
    len: usize,
    capacity: usize,
}

unsafe impl<T: Send> Send for Vec<T> {}
unsafe impl<T: Sync> Sync for Vec<T> {}

impl<T> Vec<T> {
    pub fn new() -> Self {
        assert!(
            std::mem::align_of::<T>() != 0,
            "We're not ready to handle ZSTs"
        );

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
mod test {
    use super::*;

    #[test]
    fn it_works() {
        let vec = Vec::<usize>::new();

        assert_eq!(vec.len(), 0);
        assert_eq!(vec.capacity(), 0);
    }
}
