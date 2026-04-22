#include "deque.h"

static const int BLOCK_SIZE = 64;

IntDeque::IntDeque()
{
    block_size = BLOCK_SIZE;
    map_capacity = 8;

    blockmap = new int*[map_capacity];

    for (int i = 0; i < map_capacity; i++)
    {
        blockmap[i] = 0;
    }

    start_block = map_capacity / 2;
    end_block = map_capacity / 2;

    blockmap[start_block] = new int[block_size];

    front_index = block_size / 2;
    back_index = block_size / 2;

    count = 0;
}

IntDeque::~IntDeque()
{
    for (int i = 0; i < map_capacity; i++)
    {
        if (blockmap[i] != 0)
        {
            delete[] blockmap[i];
        }
    }

    delete[] blockmap;
}

void IntDeque::reallocate_map()
{
    int new_capacity = map_capacity * 2;

    int** new_map = new int*[new_capacity];

    for (int i = 0; i < new_capacity; i++)
    {
        new_map[i] = 0;
    }

    int shift = new_capacity / 2 - map_capacity / 2;

    for (int i = 0; i < map_capacity; i++)
    {
        if (blockmap[i] != 0)
        {
            new_map[i + shift] = blockmap[i];
        }
    }

    start_block += shift;
    end_block += shift;

    delete[] blockmap;
    blockmap = new_map;
    map_capacity = new_capacity;
}

void IntDeque::push_back(int val)
{
    if (blockmap[end_block] == 0)
    {
        blockmap[end_block] = new int[block_size];
    }

    blockmap[end_block][back_index] = val;

    back_index++;
    count++;

    if (back_index == block_size)
    {
        back_index = 0;
        end_block++;

        if (end_block == map_capacity)
        {
            reallocate_map();
        }

        if (blockmap[end_block] == 0)
        {
            blockmap[end_block] = new int[block_size];
        }
    }
}

void IntDeque::push_front(int val)
{
    if (blockmap[start_block] == 0)
    {
        blockmap[start_block] = new int[block_size];
    }

    front_index--;

    if (front_index < 0)
    {
        start_block--;

        if (start_block < 0)
        {
            reallocate_map();
        }

        front_index = block_size - 1;

        if (blockmap[start_block] == 0)
        {
            blockmap[start_block] = new int[block_size];
        }
    }

    blockmap[start_block][front_index] = val;
    count++;
}

int IntDeque::pop_front()
{
    if (count == 0)
    {
        return 0;
    }

    int val = blockmap[start_block][front_index];

    front_index++;
    count--;

    if (front_index == block_size)
    {
        delete[] blockmap[start_block];
        blockmap[start_block] = 0;

        start_block++;
        front_index = 0;
    }

    return val;
}

int IntDeque::pop_back()
{
    if (count == 0)
    {
        return 0;
    }

    back_index--;

    if (back_index < 0)
    {
        end_block--;
        back_index = block_size - 1;
    }

    int val = blockmap[end_block][back_index];
    count--;

    return val;
}

int IntDeque::front() const
{
    if (count == 0)
    {
        return 0;
    }

    return blockmap[start_block][front_index];
}

int IntDeque::back() const
{
    if (count == 0)
    {
        return 0;
    }

    int idx = back_index - 1;
    int blk = end_block;

    if (idx < 0)
    {
        blk--;
        idx = block_size - 1;
    }

    return blockmap[blk][idx];
}

bool IntDeque::empty() const
{
    return count == 0;
}

int IntDeque::size() const
{
    return count;
}

int IntDeque::operator[](int i) const
{
    if (i < 0)
    {
        return 0;
    }

    if (i >= count)
    {
        return 0;
    }

    int global = front_index + i;
    int block = start_block + (global / block_size);
    int offset = global % block_size;

    return blockmap[block][offset];
}