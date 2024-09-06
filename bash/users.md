# User Management in Linux

This document provides various ways to list users on a Linux or Unix-like system and find specific user information such as user IDs.

## 1. Viewing All Users

### Using the `/etc/passwd` File

The `/etc/passwd` file contains all user account information on the system. To see all users, you can use:

```bash
cat /etc/passwd
```

Each line in this file represents a user in the following format:

```
username:x:UID:GID:User Info:Home Directory:Shell
```

more: 

```bash
man 5 passwd
```

To display only the usernames:

```bash
cut -d: -f1 /etc/passwd
```

### Using the `getent` Command

The `getent` command queries the system's user database. It can be used to list all users, and it supports network-based databases like LDAP.

To list all users:

```bash
getent passwd
```

To display only the usernames:

```bash
getent passwd | cut -d: -f1
```

### Listing System and Regular Users

- **List system users (UID < 1000):**
  
  ```bash
  awk -F: '$3 < 1000 {print $1}' /etc/passwd
  ```

- **List regular users (UID ≥ 1000):**
  
  ```bash
  awk -F: '$3 >= 1000 {print $1}' /etc/passwd
  ```

### Using the `compgen` Command

To quickly list all users:

```bash
compgen -u
```

## 2. Finding User IDs (UID)

To find the user ID (UID) of the current user:

```bash
id -u
```

To find the UID of a specific user:

```bash
id -u <username>
```

### Checking the `/etc/passwd` File

You can also find the UID of a user by searching for their entry in `/etc/passwd`:

```bash
grep <username> /etc/passwd
```

The third field in the result will be the user's UID.

## 3. Listing Currently Logged-In Users

To see the list of users currently logged into the system, use the `who` or `w` commands:

```bash
who
```

or

```bash
w
```

These commands show the usernames and other details like login time and terminal.

## 4. Programmatically Finding User IDs

If you're writing a C program and want to find the user ID of the current user, you can use the `getuid()` function. Here's a sample C program:

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    uid_t user_id = getuid(); // Get the current user ID
    printf("User ID: %d\n", user_id);
    return 0;
}
```

## Conclusion

These methods help you list and manage users on a Linux or Unix-like system. Whether you're a system administrator or developer, these commands provide an efficient way to interact with user account data.
