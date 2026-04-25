#ifndef DEQUE_H
#define DEQUE_H

/**
 * @class IntDeque
 * @brief A dynamic double-ended queue (deque) of integers.
 *
 * Implemented using a block map (2D dynamic array) to allow
 * efficient insertion and removal from both ends.
 */
class IntDeque
{
private:
    /** 2D block map storing integer blocks */
    int** blockmap;

    /** Number of integers per block */
    int block_size;

    /** Number of blocks allocated in the map */
    int map_capacity;

    /** Index of the first used block */
    int start_block;

    /** Index of the last used block */
    int end_block;

    /** Index of the front element within its block */
    int front_index;

    /** Index of the next insertion position at the back */
    int back_index;

    /** Number of elements currently stored */
    int count;

    /**
     * @brief Expands or repositions the block map when capacity is exceeded.
     */
    void reallocate_map();

public:
    /**
     * @brief Constructs an empty deque.
     */
    IntDeque();

    /**
     * @brief Destructor. Frees all dynamically allocated memory.
     */
    ~IntDeque();

    /**
     * @brief Inserts an element at the front of the deque.
     * @param val Value to insert
     */
    void push_front(int val);

    /**
     * @brief Inserts an element at the back of the deque.
     * @param val Value to insert
     */
    void push_back(int val);

    /**
     * @brief Removes and returns the front element.
     * @return Front value (returns 0 if deque is empty)
     */
    int pop_front();

    /**
     * @brief Removes and returns the back element.
     * @return Back value (returns 0 if deque is empty)
     */
    int pop_back();

    /**
     * @brief Returns the front element without removing it.
     * @return Front value (returns 0 if deque is empty)
     */
    int front() const;

    /**
     * @brief Returns the back element without removing it.
     * @return Back value (returns 0 if deque is empty)
     */
    int back() const;

    /**
     * @brief Checks whether the deque is empty.
     * @return True if empty, false otherwise
     */
    bool empty() const;

    /**
     * @brief Returns number of elements in the deque.
     * @return Size of deque
     */
    int size() const;

    /**
     * @brief Access element at index (read-only).
     * @param i Index of element
     * @return Value at index i (returns 0 if out of bounds)
     */
    int operator[](int i) const;
};

#endif
