![image](https://github.com/user-attachments/assets/9e33f2a4-e489-4643-ab22-81960a5dfa84)
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

### **Main Menu**:
![image](https://github.com/user-attachments/assets/39f2bce6-0da3-452e-8ab8-adadafb2ae7a)


### **Setting a monthly budget**:
![image](https://github.com/user-attachments/assets/81a5f485-90cf-49f1-84b6-ad399880c65b)


### **Adding Expenses**:
![image](https://github.com/user-attachments/assets/965d3f08-03a3-42e3-bef8-e03fe39b61b4)


### **Viewing Expenses**:
![image](https://github.com/user-attachments/assets/7bd6cf7f-9ed4-4c12-b142-8cf18950b8c5)


### **Viewing Monthly Summary**:
![image](https://github.com/user-attachments/assets/34c5a5cb-8f6a-41cf-8574-3ab9f69758fc)


### **Deleting an Expense**:
![image](https://github.com/user-attachments/assets/349d32dc-4630-42db-985d-ed7150e99b48)
![image](https://github.com/user-attachments/assets/5a6acffa-0370-4cf8-9d2a-ec2c352f2221)


### **Statistics and insight**:
![image](https://github.com/user-attachments/assets/15aa479b-086c-4d09-9f72-8141ecd5438b)


### **Exiting the program and saving the file**:
![image](https://github.com/user-attachments/assets/ca74476e-2d97-4254-b380-fe17e7e74fd7)

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
