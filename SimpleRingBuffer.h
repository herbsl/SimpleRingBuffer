#ifndef _SIMPLE_RING_BUFFER_H
#define _SIMPLE_RING_BUFFER_H

template <class T> class SimpleRingBuffer {
    public:
        SimpleRingBuffer(T *buffer, uint16_t max_size = 10) {
            _buffer = buffer;
            _max_size = max_size;
            
            _size = 0;
            _end = 0;

        }
    
        ~SimpleRingBuffer() {}

        uint16_t size() {
            return _size;
        }

        uint16_t max_size() {
            return _max_size;
        }

        void push_back(T item) {
            if (_size == 0) {
                _size = 1;
                _end = 0;
            }
            else if (_size < _max_size) {
                _size++;
                _end++;
            }
            else {
                _end++;
                
                if (_end >= _size) {
                    _end = 0;
                }
            }

            _buffer[_end] = item;
        }

        T at(uint16_t index) {
            uint16_t pos = index;

            if (_size >= _max_size) {
                pos += _end + 1;
                
                if (pos >= _size) {
                    pos -= _size;
                }
            }
            
            return _buffer[pos];
        }

    private:
        T *_buffer;

        uint16_t _end;
        uint16_t _size;
        uint16_t _max_size;
};

#endif
