# text-adventure-christmas-cpp (Spanish version)
# 🎄 Christmas Text Adventure Game (C++)

A C++ console game where you play as a chosen hero sent by the Wise Kings to deliver special gifts (Wi-Fi, a smartphone, and C++ books) to baby Jesus. Your journey is filled with magical choices, enemies, points, and challenges that affect your destiny. Will you succeed?

---

## 🚀 Game Features

- 📜 Rich interactive story based on Christmas traditions  
- 🎮 Turn-based decision gameplay with randomized events  
- 💀 Health, shield, and score system  
- 🎯 Difficulty levels that affect lives and points  
- 📂 Saves your score to a local file (`puntajes.txt`)  
- 🧠 Custom console UI with clearing screen and formatting  

---

## 🛠️ Requirements

- C++ Compiler (like `g++`)  
- Linux / Windows / WSL / Any terminal that supports C++  

---

## ⚙️ How to Compile

Open your terminal and run:

```bash
g++ juego_navidad.cpp -o navidad_game
```

> Replace `juego_navidad.cpp` with your actual filename if needed.

---

## ▶️ How to Play

Then run the game with:

```bash
./navidad_game
```

Follow the story and choose between different paths using numeric input (1/2/3). Make decisions wisely to keep your score and lives.

---

## 💡 Difficulty Levels

At the start, you'll choose a difficulty that sets your starting stats:

| Difficulty                      | Score | Lives | Shield |
|---------------------------------|-------|-------|--------|
| Easy (Camino del Encanto)       | 5000  | 2     | ✅      |
| Medium (Bosque Mágico)          | 5000  | 2     | ❌      |
| Hard (Duendes y Escarpos)       | 5000  | 1     | ❌      |

---

## 🎯 Game Stats

Throughout the journey, you'll see a status bar like:

```
-----------------------------------------------------
|Puntaje: 4000       Ptos de vida: 1       Escudo: 1|
-----------------------------------------------------
```

- Lose points through bad events (dragons, zombies, bandidos...)  
- Gain lives, shields, and points through good events (scrolls, statues, treasures...)

---

## 📝 Scoring System

At the end of the game (win or lose), your score is saved in `puntajes.txt`:

```
David    5000
Juan     4000
```

You can view the leaderboard from the main menu.

---

## 📂 Project Files

- `juego_navidad.cpp` → Main game file  
- `puntajes.txt` → Automatically generated score log  

---

## 📌 To Improve

- ✅ Save scores more securely  
- ✅ Use classes or structs for player state  
- ⌛ Translate fully to English  
- ⌛ Add replay/exit confirmation  
- ⌛ Export HTML or GUI version later  

---

## 👤 Author

**Santiago David Castillo**  
Computer Science Engineering Student  
🔗 [GitHub](https://github.com/Santiago193)

---

## 📜 License

MIT © Santiago David Castillo
