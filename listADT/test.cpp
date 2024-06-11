#include "linked_list_ADT.h"
#include "test.h"

#define SETUP List<int>* l{new LinkedList<int>}
#define TEARDOWN delete l

void testInitEmpty();
void testAddFunction();
void testInsert();
void testRemoveFront();
void testRemoveIdx();
void testClear();
void testInsertThrowsException();

int main(int argc, char const *argv[])
{
    testInitEmpty();
    testAddFunction();
    testInsert();
    testRemoveFront();
    testRemoveIdx();
    testClear();
    testInsertThrowsException();

    return 0;
}

void testInitEmpty()
{
    SETUP;
    
    testTrue(l->empty(), "list initially empty");

    TEARDOWN;
}

void testAddFunction()
{
    SETUP;

    l->add(5);
    testTrue(!l->empty(), "test that list isn't empty after add");
    testTrue(l->size() == 1, "test size is 1 after add");

    TEARDOWN;
}

void testInsert()
{
    SETUP;

    l->add(5);
    l->insert(7, 1);

    testTrue(l->get(1) == 7, "test that insert places 7 at pos 1");
    
    TEARDOWN;
}

void testRemoveFront()
{
    SETUP;

    l->add(5);
    l->add(7);
    l->remove();
    testTrue(l->contains(5) == -1, "test that list doesn't contain 5 after front removal");

    TEARDOWN;
}

void testRemoveIdx()
{
    SETUP;

    l->add(5);
    l->add(7);
    l->add(3);

    l->remove(2);

    testTrue(l->contains(7) == -1, "test that list doesn't contain 7 after removal");
    testTrue(l->size() == 2, "test that size is 2 after removal");

    TEARDOWN;
}

void testClear()
{
    SETUP;

    for (size_t i = 0; i < 10; ++i)
        l->add(i);
    
    l->clear();
    testTrue(l->empty(), "test that list is empty after clear");
    TEARDOWN;
}

void testInsertThrowsException()
{
    SETUP;

    try
    {
        l->insert(7, 0);
        testFail("test that insert throws exception");
    }
    catch(std::range_error&)
    {
        testPass("test that insert throws exception");
    }
    
    TEARDOWN;
}