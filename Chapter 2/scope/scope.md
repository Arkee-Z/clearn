### Scope 

> Scope is the region of program text where a particular identifier is visible (i.e., can be used to refer to the associated entity).

In my mind, the scope in C is just a visible window — precisely the valid region of a developer-named identifier(like a variable name that labels memory) — which allows people to use that label explicitly and securely during coding or compiling. 

- Scopes can indeed be nested, meaning that an inner scope (such as that of a block, function, or loop) is contained within an outer scope. Identifiers declared in an outer scope are typically visible in the inner scope, unless hidden by a declaration of the same identifier in the inner scope.


### Identifier

> An identifier is an arbitrary long sequence of digits, underscores, lowercase and uppercase Latin letters, and Unicode characters specified using \u and \U escape notation(since C99). A valid identifier must begin with a non-digit character (Latin letter, underscore, or Unicode non-digit character(since C99)). Identifiers are case-sensitive (lowercase and uppercase letters are distinct). It is implementation-defined if raw (not escaped) Unicode characters are allowed in identifiers.(since C99)

In C, an identifier is a name used for variables, functions, etc. It can be composed of digits, underscores, lowercase and uppercase Latin letters, and (since C99) Unicode characters specified using \uand \Uescape sequences. The first character must be a non-digit​ (i.e., a Latin letter, an underscore, or a Unicode non-digit character). Identifiers are case-sensitive; for example, 'myVar' and 'myvar' are different. Additionally, keywords (like int, if, return) are reserved and cannot be used as identifiers.It is implementation-defined whether raw (unescaped) Unicode characters are allowed in identifiers (since C99).

### label

A label​ is the only kind of identifier in C that has function scope. It is used to mark a statement by placing the identifier followed by a colon (`label:`). Control flow can then be transferred to that labeled statement using a `goto label;`statement. Because of its function scope, a label is visible throughout the entire function in which it is declared, even at points in the code before its label appears.