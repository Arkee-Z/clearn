### From Storage Duration to Memory Model

From the concept of [Storage Duration](storage_duration/storage_duration.md) and the various ways in which memory can be allocated for objects in C, we can derive a logical memory model that helps us understand how a C program organizes and manages its memory. This model typically consists of several distinct areas, each with its own characteristics and purposes:

- Static storage: for global and static variables;

- Automatic Storage (Stack):​ For local non-static variables, managed automatically;

- Thread Local Storage : For _Thread_local variables are allocated in a unique memory area private to each thread;

- Allocated Storage (Heap):​ For manually allocated memory (via malloc, free, etc.);

The keyword `const` is defined in the C standard as declaring an object read-only, but it does not affect the object's storage duration or scope. According to the storage duration categories mentioned earlier, a local non-static variable (declared without `static` or at global scope) has automatic storage duration and is placed on the stack. Therefore, a `const`-qualified local variable is only nominally​ read-only; its value can potentially be modified through pointers. In contrast, attempting to modify a `const` variable at file scope (a global or `static` variable) — even via a pointer — will typically cause a segmentation fault. This difference leads me to hypothesize​ that there might be a special, read-only memory area outside the four primary storage areas in the C memory model.

- Read-Only Data Segment Storage:​ For constants, string literals, and other immutable data;

Furthermore, there may be another protected segment for the program code, separate from all the data storage areas we have discussed before, because of its distinct nature as a separate entity and preventing accidental or malicious modification:

- Text (Code) Segment Storage:​ For the executable machine code of the program itself.

Both the read-only data and code segments are typically write-protected by the operating system.

OK, now here's a basic memory model for a C program:

```
+-----------------------+
|   Text Segment        |  <-- Code (executable instructions)
+-----------------------+
|   Read-Only Data      |  <-- Constants, string literals, etc.
+-----------------------+
|   Static Storage      |  <-- Global and static variables
+-----------------------+
|   Heap (Allocated)    |  <-- Dynamically allocated memory
+-----------------------+
|   Stack (Automatic)   |  <-- Local variables, function call frames
+-----------------------+
``` 

This model helps us understand how different types of variables and data are stored and accessed in a C program. But so far, we have only discussed the storage duration and memory separation. How does it organize? What sequence or layout about these areas? How do they interact? And and whether the underlying memory model is correct or sufficient as a true memory layout for a C program? These are the questions we will explore in the next section on Inference.