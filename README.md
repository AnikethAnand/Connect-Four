# Connect Four: Pop-In & Pop-Out

A modular C implementation of Connect Four with a twist: players can insert or remove tokens from the Top, Bottom, Left, or Right.

## Technical Highlights
- **Modular Architecture:** Logic is split across specific modules (Physics, Board Rendering, Win-Checking) for high readability.
- **Custom Physics:** Tokens follow gravity-based logic depending on the entry side.
- **Win Detection:** A robust 8-directional search algorithm to detect four-in-a-row.

## How to Run
1. Clone the repository.
2. Navigate to the `src` folder.
3. Compile using GCC:
   ```bash
   gcc *.c -o ../connect4.exe
4. Run ../connect4.exe
