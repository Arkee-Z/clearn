#### hello
- a classic program to print "Hello, world!" to the terminal for every beginner who is learning C language.

#### #include 
- pre-proccessor
    - replace the content by included file
#### puts
- function 
    - declared in <stdio.h> to write string args into stdout, and add a "\n" end of the string outputed.

#### EXIT_SUCCESS
- object-like macro
    - declared in <stdlib.h>, always be defined to 0, like: `#define EXIT_SUCCESS 0`

#### #define directive
> The `#define` directives define the identifier as a macro, that is they instruct the compiler to replace all successive occurrences of identifier with replacement-list, which can be optionally additionally processed. If the identifier is already defined as any type of macro, the program is ill-formed unless the definitions are identical.
- In essence, the #define directive defines an identifier as a macro, effectively creating a name that serves as an alias for a replacement list of tokens. During preprocessing, every occurrence of this identifier is replaced by the given replacement list. It's crucial to understand that this is a textual substitution; the macro identifier itself does not have a data type. The compiler only works with the already-substituted code, where the resulting tokens will then be interpreted according to the normal C type rules.

#### Object-like macros
###### Syntax:
``` C 
#define identifier replacement-list(optional)	(1)	
```
 > Object-like macros replace every occurrence of a defined `identifier` with `replacement-list`. Version (1) of the `#define` directive behaves exactly like that.
- In my understanding, object-like macros act like aliases for constants or cumbersome code fragments. The preprocessor replaces all occurrences of these aliases with their actual definitions before the compilation starts, so the compiler receives the already-expanded code.

