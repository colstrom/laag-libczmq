################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
import utils
from . import destructors
libczmq_destructors = destructors.lib

class Zloop(object):
    """
    event-driven reactor
    """

    def __init__(self):
        """
        Create a new zloop reactor
        """
        p = utils.lib.zloop_new()
        if p == utils.ffi.NULL:
            raise MemoryError("Could not allocate person")

        # ffi.gc returns a copy of the cdata object which will have the
        # destructor called when the Python object is GC'd:
        # https://cffi.readthedocs.org/en/latest/using.html#ffi-interface
        self._p = utils.ffi.gc(p, libczmq_destructors.zloop_destroy_py)

    def reader(self, sock, handler, arg):
        """
        Register socket reader with the reactor. When the reader has messages,
        the reactor will call the handler, passing the arg. Returns 0 if OK, -1
        if there was an error. If you register the same socket more than once,
        each instance will invoke its corresponding handler.
        """
        return utils.lib.zloop_reader(self._p, sock._p, handler, arg._p)

    def reader_end(self, sock):
        """
        Cancel a socket reader from the reactor. If multiple readers exist for
        same socket, cancels ALL of them.
        """
        utils.lib.zloop_reader_end(self._p, sock._p)

    def reader_set_tolerant(self, sock):
        """
        Configure a registered reader to ignore errors. If you do not set this,
        then readers that have errors are removed from the reactor silently.
        """
        utils.lib.zloop_reader_set_tolerant(self._p, sock._p)

    def poller(self, item, handler, arg):
        """
        Register low-level libzmq pollitem with the reactor. When the pollitem
        is ready, will call the handler, passing the arg. Returns 0 if OK, -1
        if there was an error. If you register the pollitem more than once, each
        instance will invoke its corresponding handler. A pollitem with
        socket=NULL and fd=0 means 'poll on FD zero'.
        """
        return utils.lib.zloop_poller(self._p, item._p, handler, arg._p)

    def poller_end(self, item):
        """
        Cancel a pollitem from the reactor, specified by socket or FD. If both
        are specified, uses only socket. If multiple poll items exist for same
        socket/FD, cancels ALL of them.
        """
        utils.lib.zloop_poller_end(self._p, item._p)

    def poller_set_tolerant(self, item):
        """
        Configure a registered poller to ignore errors. If you do not set this,
        then poller that have errors are removed from the reactor silently.
        """
        utils.lib.zloop_poller_set_tolerant(self._p, item._p)

    def timer(self, delay, times, handler, arg):
        """
        Register a timer that expires after some delay and repeats some number of
        times. At each expiry, will call the handler, passing the arg. To run a
        timer forever, use 0 times. Returns a timer_id that is used to cancel the
        timer in the future. Returns -1 if there was an error.
        """
        return utils.lib.zloop_timer(self._p, delay, times, handler, arg._p)

    def timer_end(self, timer_id):
        """
        Cancel a specific timer identified by a specific timer_id (as returned by
        zloop_timer).
        """
        return utils.lib.zloop_timer_end(self._p, timer_id)

    def ticket(self, handler, arg):
        """
        Register a ticket timer. Ticket timers are very fast in the case where
        you use a lot of timers (thousands), and frequently remove and add them.
        The main use case is expiry timers for servers that handle many clients,
        and which reset the expiry timer for each message received from a client.
        Whereas normal timers perform poorly as the number of clients grows, the
        cost of ticket timers is constant, no matter the number of clients. You
        must set the ticket delay using zloop_set_ticket_delay before creating a
        ticket. Returns a handle to the timer that you should use in
        zloop_ticket_reset and zloop_ticket_delete.
        """
        return utils.lib.zloop_ticket(self._p, handler, arg._p)

    def ticket_reset(self, handle):
        """
        Reset a ticket timer, which moves it to the end of the ticket list and
        resets its execution time. This is a very fast operation.
        """
        utils.lib.zloop_ticket_reset(self._p, handle._p)

    def ticket_delete(self, handle):
        """
        Delete a ticket timer. We do not actually delete the ticket here, as
        other code may still refer to the ticket. We mark as deleted, and remove
        later and safely.
        """
        utils.lib.zloop_ticket_delete(self._p, handle._p)

    def set_ticket_delay(self, ticket_delay):
        """
        Set the ticket delay, which applies to all tickets. If you lower the
        delay and there are already tickets created, the results are undefined.
        """
        utils.lib.zloop_set_ticket_delay(self._p, ticket_delay)

    def set_max_timers(self, max_timers):
        """
        Set hard limit on number of timers allowed. Setting more than a small
        number of timers (10-100) can have a dramatic impact on the performance
        of the reactor. For high-volume cases, use ticket timers. If the hard
        limit is reached, the reactor stops creating new timers and logs an
        error.
        """
        utils.lib.zloop_set_max_timers(self._p, max_timers)

    def set_verbose(self, verbose):
        """
        Set verbose tracing of reactor on/off. The default verbose setting is
        off (false).
        """
        utils.lib.zloop_set_verbose(self._p, verbose)

    def set_nonstop(self, nonstop):
        """
        By default the reactor stops if the process receives a SIGINT or SIGTERM
        signal. This makes it impossible to shut-down message based architectures
        like zactors. This method lets you switch off break handling. The default
        nonstop setting is off (false).
        """
        utils.lib.zloop_set_nonstop(self._p, nonstop)

    def start(self):
        """
        Start the reactor. Takes control of the thread and returns when the 0MQ
        context is terminated or the process is interrupted, or any event handler
        returns -1. Event handlers may register new sockets and timers, and
        cancel sockets. Returns 0 if interrupted, -1 if canceled by a handler.
        """
        return utils.lib.zloop_start(self._p)

    def test(verbose):
        """
        Self test of this class.
        """
        utils.lib.zloop_test(verbose)

################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
