<h1 align="center">Get Next Line 42 Lisboa 📖</h1>

```c
            /* ************************************************************************** */
            /*                                                                            */
            /*                                                        :::      ::::::::   */
            /*   Get Next Line                                     :+:      :+:    :+:   */
            /*                                                    +:+ +:+         +:+     */
            /*   By: dbaltaza <marvin@42.fr>                    +#+  +:+       +#+        */
            /*                                                +#+#+#+#+#+   +#+           */
            /*   Created: 2025/10/30 by dbaltaza                  #+#    #+#             */
            /*   Updated: 2025/10/30 by dbaltaza                 ###   ########.fr       */
            /*                                                                            */
            /* ************************************************************************** */
```

## 📋 About

A function that reads a line from a file descriptor, one line at a time.

**Grade:** --/125

---

## 🎯 Function Prototype

```c
char *get_next_line(int fd);
```

**Returns:**
- Line read including `\n` (if present)
- `NULL` if end of file or error

---

## 📂 Files

**Mandatory:**
- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

**Bonus:**
- `get_next_line_bonus.c`
- `get_next_line_utils_bonus.c`
- `get_next_line_bonus.h`

---

## ⚙️ Compilation

```bash
# Compile with BUFFER_SIZE
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

# Test different buffer sizes
cc -D BUFFER_SIZE=1 ...
cc -D BUFFER_SIZE=9999 ...
```

---

## ✅ Requirements

✅ Works with different `BUFFER_SIZE` values  
✅ Reads from file and standard input  
✅ No memory leaks  
✅ Only one static variable allowed  
✅ Bonus: Handle multiple fd simultaneously  

**Allowed functions:** `read`, `malloc`, `free`

---

## 💡 Key Concepts

- Static variables
- Dynamic memory allocation
- Buffer management
- File descriptor manipulation
- Edge cases handling

---

## 🧪 Testing

```bash
# Test with files
./a.out < test.txt

# Test with different buffer sizes
cc -D BUFFER_SIZE=1 ...
cc -D BUFFER_SIZE=42 ...
cc -D BUFFER_SIZE=10000 ...

# Check memory leaks
valgrind --leak-check=full ./a.out
```

---

**Made by:** dbaltaza  
**Campus:** 42 Lisboa  
**Year:** 2025
