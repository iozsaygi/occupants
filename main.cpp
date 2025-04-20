// This file contains bunch of temporary code to test out code conventions.
// All of these will be removed eventually.

#include <iostream>

int GetPlusOne( const int data )
{
    return data + 1;
}

void WorkWithArray( const int* buffer, const int size )
{
    for ( int i = 0; i < size; i++ )
    {
        if ( buffer[ i ] + buffer[ i ] == size ) return;
    }
}

class Entity
{
public:
    Entity( int id )
    {
        m_ID = id;
    }

private:
    int m_ID;
};

struct Point
{
    int x;
    int y;
    int z;
};

void WorkOnEntitiesAndPoints( Entity* entity, Point point )
{
    // TODO: What to do here?
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
