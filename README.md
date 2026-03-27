# 📦 vector_dz

## 📖 Description

`vector_dz` is a learning project that implements a custom version of the `vector` container from C++.
The goal is to understand how dynamic arrays, memory management, and templates work internally.

---

## 🎯 Features

The implemented `vector<T>` class supports:

* ➕ adding elements (`push_back`)
* ➖ removing the last element (`pop_back`)
* 🔍 element access via `operator[]`
* 📏 getting the number of elements (`size`)
* 📦 working with capacity (`capacity`)
* 🔄 automatic memory reallocation

---

## 🧱 Project Structure

```
vector_dz/
│
├── main.cpp      # usage example
├── vector.h      # vector implementation
└── README.md     # documentation
```

---

## 🚀 Getting Started

### 🔧 Requirements

* C++ compiler (g++, clang, or MSVC)
* C++11 standard or newer

### ▶️ Compile

```bash
g++ main.cpp -o vector
```

### ▶️ Run

```bash
./vector
```

---

## 💡 Usage Example

```cpp
#include <iostream>
#include "vector.h"

int main() {
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }

    return 0;
}
```

---

## 🧠 What You Learn

* dynamic memory management (`new/delete`)
* templates (`template<typename T>`)
* basics of STL container design
* object copying principles

---

## ⚠️ Limitations

* no iterators implemented
* not fully STL-compliant
* basic error handling only

---

## 👤 Author

GitHub: [https://github.com/termoSSD](https://github.com/termoSSD)

---

## 📜 License

This project is created for educational purposes only.
