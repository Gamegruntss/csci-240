#include "linked_deque.h"
#include "test.h"

#define SETUP Deque<int>* d{new LinkedDeque<int>}
#define TEARDOWN delete d

void testInitEmpty();
void testEnqueueFront();
void testEnqueueBack();
void testDequeueFront();
void testDequeueBack();

int main(int argc, char const *argv[])
{
    testInitEmpty();
    testEnqueueFront();
    testEnqueueBack();
    testDequeueFront();
    testDequeueBack();

    return 0;
}

void testInitEmpty()
{
    SETUP;

    testTrue(d->empty(), "test that deque initially empty.");

    TEARDOWN;
}

void testEnqueueFront()
{
    SETUP;

    d->enqueueFront(1);
    d->enqueueFront(3);
    d->enqueueFront(7);

    testTrue(d->front() == 7, "test that enqueueFront places node at front");

    TEARDOWN;
}

void testEnqueueBack()
{
    SETUP;

    d->enqueueBack(7);
    d->enqueueBack(3);
    d->enqueueBack(1);

    testTrue(d->back() == 1, "test that enqueueBack places node at back");

    TEARDOWN;
}

void testDequeueFront()
{
    SETUP;

    d->enqueueFront(1);
    d->enqueueFront(3);
    d->enqueueFront(7);

    d->dequeueFront();

    testTrue(d->front() != 7, "test that dequeueFront removes node at front");

    TEARDOWN;
}

void testDequeueBack()
{
    SETUP;

    d->enqueueBack(7);
    d->enqueueBack(3);
    d->enqueueBack(1);

    d->dequeueBack();

    testTrue(d->back() != 1, "test that dequeueBack removes node at back");

    TEARDOWN;
}
