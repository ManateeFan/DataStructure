# string class

## String API

### Constructors

```
String ( )
String (char)
String (const char*)
String (const String& s)
```

### Informational Methods

```
unsigned   len ( ) const
int index (char) const
```

### Case Methods

```
void     upcase (unsigned first, unsigned last)
void   downcase (unsigned first, unsigned last)
void togglecase (unsigned first, unsigned last)
```

### Stream Operators

```
friend std::ostream& operator<< (std::ostream&, const String&)
friend std::istream& operator>> (std::istream&, String&)
```

### Accessor Operators

```
char operator[] (unsigned) const
char& operator[] (unsigned)
```

### Assignment Operators

```
String&  operator= (const String&)
String& operator+= (const String&)
```

### String Concatenation

```
friend String operator+ (const String&, const String&) Concat two Strings
friend String operator+ (const String&, char)
friend String operator+ (const String&, const char*)
friend String operator+ (char, const String&)
friend String operator+ (const char*, const String&)
```

### Logical Operators

All argument permutations in concatenation are repeated here, also.
```
friend bool operator== (const String&, const String&) Equality
friend bool operator!= (const String&, const String&) Non-Equality
friend bool  operator< (const String&, const String&) Less-than Inequality
friend bool  operator> (const String&, const String&) Greater-than Inequality
friend bool operator<= (const String&, const String&) Less-than or Equailty
friend bool operator>= (const String&, const String&) Greater-than or Equality
```