# ft_printf 
⚠️ Disclaimer: This project is released for educational purposes. As plagiarism is strictly forbidden within the 42 curriculum, please do not copy-paste this code without fully understanding it.

#### 📖 Summary
The goal of this project is to recode the famous printf function from the C standard library. This project provides a deep dive into managing variadic functions (variable number of arguments) and structuring code capable of parsing and formatting complex strings.
#### 🚀 Features
My implementation reproduces the behavior of the original, including buffer management and returning the number of printed characters.

**Supported Conversions**
 - `%c` : Single character.
 - `%s` : String.
 - `%p` : Pointer address (in hexadecimal).
 - `%d` / `%i` : Signed decimal integer.
 - `%u` : Unsigned decimal integer.
 - `%x` : Hexadecimal (lowercase).
 - `%X` : Hexadecimal (uppercase).
 - `%%` : The percentage sign itself.

**Bonus**  
This version includes full support for the following flag combinations:
 - Alignment and Padding: `-` (left alignment), `0` (zero padding).
 - Precision and Width: `.` (precision), minimum field width management.
 - Prefixes and Signs: `#` (0x/0X prefix), `+` (forces sign display), ` ` (space for positive numbers).
