/*
 * INVOKING INDENT
 */
// --standard-output // Write to standard output.
// --ignore-profile // Do not read ‘.indent.pro’ files. Hmmm, kinda too late, isn't it?


/*
 * COMMON STYLES
 */
// --gnu-style // Use GNU coding style.  This is the default.
--k-and-r-style // Use Kernighan & Ritchie coding style.
// --original // Use the original Berkeley coding style.
// --linux-style // Use Linux coding style.


/*
 * BLANK LINES
 */
// --blank-lines-after-declarations // Force blank lines after the declarations.
// --no-blank-lines-after-declarations // Do not force blank lines after declarations.

// --blank-lines-after-procedures // Force blank lines after procedure bodies.
// --no-blank-lines-after-procedures // Do not force blank lines after procedure bodies.

// --blank-lines-before-block-comments // Force blank lines before block comments.

// --swallow-optional-blank-lines // Swallow optional blank lines.
// --leave-optional-blank-lines // Do not swallow optional blank lines.


/*
 * COMMENTS
 */
// --format-all-comments // Do not disable all formatting of comments.
// --dont-format-comments // Do not format any comments.

// --comment-indentationn // Put comments to the right of code in column n.
// --line-comments-indentationn // Set indentation of comments not to the right of code to n spaces.
// --declaration-comment-columnn // Put comments to the right of the declarations in column n.

// --comment-delimiters-on-blank-lines // Put comment delimiters on blank lines.
// --no-comment-delimiters-on-blank-lines // Do not put comment delimiters on blank lines.

// --format-first-column-comments // Format comments in the first column.
// --dont-format-first-column-comments // Do not format comments in the first column as normal.

// --comment-line-lengthn // Set maximum line length for comment formatting to n.
// --dont-star-comments // Do not put the ‘*’ character at the left of comments.
// --start-left-side-of-comments // Put the ‘*’ character at the left of comments.


/*
 * STATEMENTS
 */
// --space-after-if // Put a space after each if.
--no-space-after-if // Do not put a space after every if.
// --braces-on-if-line // Put braces on line with if, etc.
--braces-after-if-line // Put braces on line after if, etc.
// --cuddle-else // Cuddle else and preceding ‘}’.
// --dont-cuddle-else // Do not cuddle } and else.

// --space-after-for // Put a space after each for.
--no-space-after-for // Do not put a space after every for.

// --space-after-while // Put a space after each while.
--no-space-after-while // Do not put a space after every while.
// --cuddle-do-while // Cuddle while of do {} while; and preceding ‘}’.
--dont-cuddle-do-while // Do not cuddle } and the while of a do {} while;.

// --case-brace-indentationn // Indent braces after a case label N spaces.
--case-indentation4 // Case label indent of n spaces.

// --struct-brace-indentationn // Indent braces of a struct, union or enum N spaces.

--brace-indent0 // Indent braces n spaces.
--continuation-indentation4 // Continuation indent of n spaces.

// --space-after-procedure-calls // Insert a space between the name of the procedure being called and the ‘(’.
// --no-space-after-function-call-names // Do not put space after the function in function calls.

// --space-after-parentheses // Put a space after every ’(’ and before every ’)’.
// --no-space-after-parentheses // Do not put a space after every ’(’ and before every ’)’.
// --paren-indentationn // Specify the extra indentation per open parentheses ’(’ when a statement is bro‐
// --dont-line-up-parentheses // Do not line up parentheses.

// --space-after-cast // Put a space after a cast operator.
// --no-space-after-casts // Do not put a space after cast operators.

// --space-special-semicolon // On one-line for and while statements, force a blank before the semicolon.
// --dont-space-special-semicolon // Do not force a space before the semicolon after certain statements. Disables ‘-ss’.

// --blank-before-sizeof // Put a space between sizeof and its argument.


/*
 * DECLARATIONS
 */
// --declaration-indentationn // Put variables in column n.
// --blank-lines-after-commas // Force newline after comma in declaration.
// --no-blank-lines-after-commas // Do not force newlines after commas in declarations.

// --break-function-decl-args // Break the line before all arguments in a declaration.
// --dont-break-function-decl-args // Don’t put each argument in a function declaration on a separate line.
// --break-function-decl-args-end // Break the line after the last argument in a declaration.

// --procnames-start-lines // Put the type of a procedure on the line before its name.
// --dont-break-procedure-type // Put the type of a procedure on the same line as its name.

// -T // Tell indent the name of typenames.

// --braces-on-func-def-line // Put braces on function definition line.
// --braces-after-func-def-line // Put braces on line following function definition line.

// --braces-on-struct-decl-line // Put braces on struct declaration line.
// --braces-after-struct-decl-line // Put braces on the line after struct declaration lines.

// --left-justify-declarations // If -cd 0 is used then comments after declarations are left justified  behind  the declaration.
// --dont-left-justify-declarations // Comments  after  declarations are treated the same as comments after other statments.


/*
 * INDENTATION
 */
--indent-level4 // Set indentation level to n spaces.

// --use-tabs // Use tabs. This is the default.
--no-tabs // Use spaces instead of tabs.
// --tab-sizen // Set tab size to n spaces.

// --parameter-indentationn // Indent parameter types in old-style function definitions by n spaces.
// --no-parameter-indentation // Zero width indentation for parameters.

--continue-at-parentheses // Line up continued lines at parentheses.

// --leave-preprocessor-space // Leave space between ‘#’ and preprocessor directive.
// --preprocessor-indentationn // Specify the indentation for preprocessor conditional statements.

// --indent-labeln // Set offset for labels to column n.


/*
 * BREAKING LONG LINES
 */
--line-length72 // Set maximum line length for non-comment lines to n.

// --break-before-boolean-operator // Prefer to break long lines before boolean operators.
// --break-after-boolean-operator // Do not prefer to break long lines before boolean operators.

// --honour-newlines // Prefer to break long lines at the position of newlines in the input.
// --ignore-newlines // Do not prefer to break long lines at the position of newlines in the input.


/*
 * MISCELLANEOUS OPTIONS
 */
// --verbose // Enable verbose mode.
// --no-verbosity // Disable verbose mode.

// --preserve-mtime // Preserve  access  and  modification  times   on   output   files.

// --else-endif-columnn // Put comments to the right of #else and #endif statements in column n.

// -version // Output the version number of indent.
