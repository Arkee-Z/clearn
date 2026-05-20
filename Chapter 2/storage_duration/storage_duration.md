### Storage Duration

Storage duration​ is a property of an object that defines the **minimum potential lifetime**​ of the memory in which it resides. The storage duration is determined by the form of **declaration** or **allocation method** used to obtain storage for the object and is one of the following:

- **static storage duration**: 

    > The storage duration is the entire execution of the program, and the value stored in the object is initialized only once, prior to main function. All objects declared `static` and all objects with either internal or external linkage that aren't declared `_Thread_local` (until C23) `thread_local` (since C23)(since C11) have this storage duration.

    declared at file scope (outside any function) with or without `static`, or declared `static` inside a block.

- **thread storage duration**: 

    > The storage duration is the entire execution of the thread in which it was created, and the value stored in the object is initialized when the thread is started. Each thread has its own, distinct, object. If the thread that executes the expression that accesses this object is not the thread that executed its initialization, the behavior is implementation-defined. All objects declared `_Thread_local` (until C23) `thread_local` (since C23) have this storage duration.

    declared with `_Thread_local` (C11).

- **automatic storage duration**: 

    > The storage is allocated when the block in which the object was declared is entered and deallocated when it is exited by any means (goto, return, reaching the end). One exception is the VLAs; their storage is allocated when the declaration is executed, not on block entry, and deallocated when the declaration goes out of scope, not when the block is exited (since C99). If the block is entered recursively, a new allocation is performed for every recursion level. All function parameters and non-static block-scope objects have this storage duration, as well as compound literals used at block scope (until C23).

    declared inside a block without `static` or `_Thread_local` (includes parameters).

- **allocated storage duration**: 

    > The storage is allocated and deallocated on request, using dynamic memory allocation functions.

    allocated by `malloc`, `calloc`, `realloc`, or `aligned_alloc`.

### static

> The static specifier specifies both static storage duration (unless combined with _Thread_local)(since C11) and internal linkage (unless used at block scope). It can be used with functions at file scope and with variables at both file and block scope, but not in function parameter lists.

#### Core Insight: The Essence of `static`

The fundamental nature of static is "Restriction and Persistence".

- At the file scope, it restricts the visibility of a name (from global to file-local).

- Inside a function (block scope), it establishes persistence for the lifetime of an entity (from temporary to permanent).

#### Mapping to My Conceptual Framework

This dual role operates on two distinct dimensions of the C language:

- **Storage Duration**:

    - When you declare a variable `static` **inside a function**, you change its **storage duration** from automatic to static.

    - **What does this mean?** The variable's storage locaton moves from the **runtime stack** (allocated per function call) to either the `.data` or `.bss` segment (determined at program load, based on initialization).

    - **The Result**: It is initialized (or zeroed) **before `main()` starts**, retains its value **after the function returns**, and will hold its modified value on the **next function call**. Its lifetime matches that of a global variable.

- **Linkage and Scope**:

    - When you declare a variable or function `static` at **file scope**, you give it **internal linkage**.

    - **What does this mean?** The name (sumbol) is **not placed in the linker's global symbol table**. Other source files are completely unaware of its existence, preventing name conflicts or accidental linkage.

    - **The Result**: You can have, for example, a `static int helper;` or a `static void calculate() { ... }` in ten different `.c` files. They are entirely independent, private entities. This is the key to creating "private" global variables and "private" helper functions.

##### Something instructions:

A static object must be initialized with a constant expression. Acceptable constants include literals (like `1`, `'a'`, or `0xff`), members of an `enum`, or the results of `alignof` or `sizeof` operators. A `const` variable is not​ considered a constant expression in this context.

- But we can see a specific example in **GCC 8+**, as shown in the `try_something_invalid` directory. In that directory, a file uses a `const int` variable to initialize a static array, which is non-conforming. However, GCC 8+ does not report an error for it.