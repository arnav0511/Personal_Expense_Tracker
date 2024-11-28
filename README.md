
# **Personal Expense Tracker**

A comprehensive **C-based Personal Expense Tracker** that helps you efficiently manage your finances by tracking monthly expenses, comparing them against a set budget, and providing detailed insights. This project emphasizes simplicity, accuracy, and clarity in financial management.

---

## **Features**

- **Expense Logging**: Record and manage daily expenses.
- **Budget Setting**: Define monthly budgets and track deviations.
- **Month-Year Organization**: Automatically organizes data by month and year.
- **Chronological Sorting**: Displays expenses in descending chronological order for easy reference.
- **Insights**:
  - Total monthly expenses.
  - Budget comparisons with clear over-budget or under-budget indicators.

---

## **Usage**

1. **Start by Setting a Budget**:
   - Enter your monthly budget to keep your spending on track.

2. **Add Expenses**:
   - Provide details for each expense: date, category, amount, and description.

3. **View Monthly Reports**:
   - Analyze expenses grouped by month-year.
   - Understand trends and deviations from the budget.

4. **Export Data**:
   - Save reports in structured files for offline analysis.

---

## **How It Works**

1. **Data Input**:
   - User inputs expenses with date and description.
2. **Processing**:
   - The program organizes and calculates total monthly expenditures.
3. **Output**:
   - Displays sorted data, highlights over-budget months, and provides visualized summaries.

---

## **Technical Details**

### **Languages & Tools**
- **Language**: C
- **File Handling**:
  - Reads/Writes to structured files for persistent storage.
- **Sorting Algorithm**:
  - Bubble sort for organizing data by month-year in descending order.

### **Key Algorithms**
- **Month-Year Parsing**:
  - Extracts month-year from dates to ensure organized data.
- **Chronological Sorting**:
  - Ensures reports are easy to read and up-to-date.
- **Error Handling**:
  - Handles incorrect inputs gracefully to ensure smooth usage.

---

## **Setup**

### **Requirements**
- GCC Compiler or equivalent C compiler.
- Basic understanding of C and file handling.

### **Installation**
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/personal-expense-tracker.git
   ```
2. Navigate to the project directory:
   ```bash
   cd personal-expense-tracker
   ```
3. Compile the program:
   ```bash
   gcc expense_tracker.c -o expense_tracker
   ```
4. Run the program:
   ```bash
   ./expense_tracker
   ```

---

## **Screenshots**

### **Input Example**:
```
Enter expense details (Date [DD-MM-YYYY], Description, Amount):
15-11-2024 | Coffee | 150.00
```

### **Output Example**:
```
Month-Year     Total Expenses     Budget    Status
----------------------------------------------------
11-2024        ₹ 5000.00          ₹ 4500.00 OVER BUDGET
10-2024        ₹ 4000.00          ₹ 4500.00 UNDER BUDGET
```

---

## **Roadmap**

- [ ] Add data visualization (e.g., pie charts for category-wise spending).
- [ ] Integrate automated reports export to Excel/CSV format.
- [ ] Add password protection for personal data.

---

## **Contributing**

Contributions are welcome! To contribute:
1. Fork this repository.
2. Create a feature branch:
   ```bash
   git checkout -b feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -m "Add feature-name"
   ```
4. Push to the branch:
   ```bash
   git push origin feature-name
   ```
5. Create a pull request.

---

## **License**

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for more details.

---

## **Acknowledgements**

- Inspiration: The need for simple and effective budget management.
- Language: C, for its simplicity and versatility.
