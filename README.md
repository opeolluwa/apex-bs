# 🏦 Non-GUI Banking System Features in C, Rust, Go, and JavaScript (Node.js)

A curated list of non-GUI banking system features you can implement in **C**, **Rust**, **Go**, and **JavaScript (Node.js)** to help you **relearn** and compare the strengths of each language. These features focus on **core logic**, **file I/O**, **data structures**, **concurrency**, and **error handling**—all excellent areas for skill sharpening.

---

## ✅ General Scope

Each language will build a **modular banking backend** with the following core features:

- Account creation  
- Deposit/withdrawal  
- Transfer between accounts  
- Transaction history  
- Basic authentication  
- Persistence (file or in-memory DB)  
- **Optional**: concurrency, unit testing, CLI interaction  

---

## 🔹 C — Low-level Systems and Memory Management

**🎯 Goal**: Reinforce understanding of pointers, structs, file I/O, and manual memory management.

### Suggested Features:
- Define `struct` for `Account` and `Transaction`
- Store data in plain text or binary files (manual serialization)
- Use file-based locking for simple concurrent access
- Implement a simple menu-driven CLI (e.g., `scanf`)
- Implement custom linked list or array-based storage
- Validate user PIN using simple hashing (optional)

**🔧 Focus Areas**:  
Pointers, file I/O (`fopen`, `fread`, `fwrite`), error handling, memory leaks, `malloc`/`free`.

---

## 🔸 Rust — Safety and Concurrency

**🎯 Goal**: Practice ownership, borrowing, enums, and error handling with `Result`.

### Suggested Features:
- Define structs with ownership (`Account`, `Bank`, `Transaction`)
- Use `HashMap` for in-memory account storage
- Persist using `serde` and `serde_json` or `bincode`
- Use `Result`/`Option` idioms for error handling
- Add multi-threaded transaction simulation using `tokio` or threads
- Unit tests for transfer, deposit, etc.

**🔧 Focus Areas**:  
Ownership, lifetimes, `Result`, modules, error handling, concurrency, testing.

---

## 🔹 Go — Simplicity and Concurrency

**🎯 Goal**: Emphasize goroutines, channels, structs, and interfaces.

### Suggested Features:
- Define account structs with methods
- Use goroutines and channels to simulate concurrent transfers
- JSON-based persistence via `encoding/json`
- Simulate delayed transactions using `time.Sleep`
- Use maps + mutexes for thread-safe account storage
- Add CLI using standard input

**🔧 Focus Areas**:  
Goroutines, channels, struct methods, `interface{}`, JSON, `sync.Mutex`.

---

## 🔸 JavaScript (Node.js) — Async Logic & JSON Handling

**🎯 Goal**: Focus on async I/O, data manipulation, and modular code.

### Suggested Features:
- Use in-memory `Map` or persist to JSON files
- Handle commands from CLI using `readline`
- Simulate async transactions with `setTimeout`/`Promise`
- Store transactions and accounts in nested JSON
- Write modular code using ES modules (or CommonJS)
- Implement rudimentary authentication with `bcrypt`

**🔧 Focus Areas**:  
`async/await`, file system module (`fs.promises`), JSON, modular design, error handling.

---

## 🧪 Bonus Ideas (for All Languages)

- Logging system (logs all operations with timestamps)
- Basic auth system (PIN/password protected accounts)
- Interest calculator (periodic interest on balance)
- Scheduled transactions (delayed transfers)
- Transaction rollback on error (simulate atomicity)
- Audit trail feature for each account

---

