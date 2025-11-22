//leading to a quicker resolution.
//Debugger and threads
//How does the Java debugger figure out where exactly to pause the
//execution of a running application? The answer again is threading. By
//attaching itself to the various threads in the application, the debugger can
//select which of these individual threads to examine or even change their
//state while debugging an active application. This is fundamental to your
//ability to find and fix bugs in applications where several threads might be
//simultaneously executing at different stages, and where different threads
//might be interacting in ways that need to be understood.
//Each action can be “stepped into,” “stepped over,” or “stepped out of” with
//respect to a thread. One or more independent call stacks for the active
//threads may be inspected in a debugging session. The call stack tells you
//what happened before, such as what caused a thread to be at a given point
//in a program. Understanding how a thread got to a certain state is
//invaluable when you’re trying to figure out the cause of an unexpected
//exception or an erroneous data manipulation.

public class DebuggerAndThread{
    public static void main(String args[])  //the main thread
    
}