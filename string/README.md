# string class

## Test

    [main.cpp](https://github.com/vlyf/DataStructure/blob/master/string/string.cpp)

## String API

### Constructors

```
string();
string(const char& ch);
string(const char* str);
string(const string& str);
```

### Informational Methods

```
unsigned Length() const;
int Index(char c) const;
```

### Case Methods

```
void UpCase(unsigned first, unsigned last);
void LowCase(unsigned first, unsigned last);
```

### Stream Operators

```
friend std::ostream& operator<<(std::ostream& os, const string& str);
friend std::istream& operator>>(std::istream& is, string& str);
```

### Accessor Operators

```
const char& operator[](unsigned i) const;
char& operator[](unsigned i);
```

### Assignment Operators

```
String&  operator= (const String&)
String& operator+= (const String&)
```

### String Concatenation

```
friend string operator+(const string& lhs, const string& rhs);
friend string operator+(const string& lhs, const char* rhs);
friend string operator+(const char* lhs, const string& rhs);
```

### Logical Operators

```
friend bool operator==(const string& lhs, const string& rhs);
friend bool operator!=(const string& lhs, const string& rhs);
friend bool operator<(const string& lhs, const string& rhs);
friend bool operator>(const string& lhs, const string& rhs);
```