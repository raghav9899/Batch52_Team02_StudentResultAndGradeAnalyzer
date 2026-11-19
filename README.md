# Student Result and Grade Analyzer

A C programming project that processes marks for multiple students,
calculates individual results, and summarizes class performance.

## 1. Project Details

-   **Project title:** Student Result and Grade Analyzer
-   **Programming language:** C
-   **Source file:** `StudentResultAndGradeAnalyzer.c`
-   **Maximum students:** 50
-   **Subjects per student:** 5
-   **Maximum marks per subject:** 100

### Team Information

-   **Team number:** `02`
-   **Batch:** `52`

### Team Members

1.  `Raghav Goyal`
2.  `Abhinav Chatterjee`
3.  `Namish Rawat`

## 2. Problem Statement

Develop a result-processing program that calculates student performance
across multiple subjects.

The program accepts marks for five subjects for multiple students and
calculates each student's total marks, percentage, and grade. It
determines pass or fail status using a minimum required mark in each
subject. It also identifies the class topper and calculates the class
average.

## 3. Objectives

-   Calculate the total marks obtained by each student.
-   Calculate each student's percentage.
-   Assign a grade based on the percentage.
-   Determine pass or fail status using the subject-wise passing
    requirement.
-   Identify the student with the highest total marks.
-   Calculate and display the class average.

## 4. Features

-   Accepts marks for five subjects per student.
-   Supports up to 50 students.
-   Checks that the number of students is between 1 and 50.
-   Accepts subject marks from 0 to 100 and asks again if a mark is
    outside that range.
-   Calculates total marks out of 500.
-   Calculates percentage and assigns a grade.
-   A student passes only if they score at least 35 in every subject.
-   Displays each student's result.
-   Displays the class topper and class average.

## 5. Grading and Passing Criteria

  Percentage   Grade
  ------------ -------
  90--100%     A
  75--89.99%   B
  60--74.99%   C
  40--59.99%   D
  Below 40%    F

**Passing rule:** A student must score at least 35 marks in every
subject to pass. A student can receive a grade based on their percentage
and still fail if they score below 35 in any subject.

## 6. Algorithm

1.  Start the program.
2.  Ask for the number of students.
3.  Check that the number is between 1 and 50. If it is invalid, display
    an error and stop.
4.  For each student:
    -   Initialize their total to 0 and pass status to true.
    -   Read marks for all five subjects.
    -   Reject marks below 0 or above 100 and ask for a valid mark.
    -   Add each valid mark to the student's total.
    -   If any subject mark is below 35, set the student's pass status
        to false.
    -   Calculate the percentage by dividing the total by 5.
    -   Assign a grade based on the percentage.
    -   Add the percentage to the class total.
    -   Update the topper if this student's total is higher than the
        current highest total.
5.  Display every student's total, percentage, grade, and pass/fail
    status.
6.  Display the class topper and their total marks.
7.  Calculate and display the class average percentage.
8.  End the program.

## 7. Pseudocode

``` text
START

INPUT number_of_students

IF number_of_students < 1 OR number_of_students > 50
    DISPLAY "Invalid number of students"
    STOP
END IF

topper = 0
classTotal = 0

FOR each student i
    total[i] = 0
    pass[i] = TRUE

    FOR each subject j from 0 to 4
        INPUT marks[i][j]

        WHILE marks[i][j] < 0 OR marks[i][j] > 100
            DISPLAY "Invalid marks"
            INPUT marks[i][j] again
        END WHILE

        total[i] = total[i] + marks[i][j]

        IF marks[i][j] < 35
            pass[i] = FALSE
        END IF
    END FOR

    percentage[i] = total[i] / 5.0

    IF percentage[i] >= 90
        grade[i] = 'A'
    ELSE IF percentage[i] >= 75
        grade[i] = 'B'
    ELSE IF percentage[i] >= 60
        grade[i] = 'C'
    ELSE IF percentage[i] >= 40
        grade[i] = 'D'
    ELSE
        grade[i] = 'F'
    END IF

    classTotal = classTotal + percentage[i]

    IF total[i] > total[topper]
        topper = i
    END IF
END FOR

DISPLAY student-wise results
DISPLAY class topper
DISPLAY classTotal / number_of_students

STOP
```

## 8. Flowchart

The program follows this general flow:

``` mermaid
flowchart TD
    A([Start]) --> B[/Enter number of students/]
    B --> C[Initialize student index]
    C --> D{More students?}
    D -- Yes --> E[Set total = 0 and pass = true]
    E --> F[Enter marks for five subjects]
    F --> G{Any subject mark below 35?}
    G -- Yes --> H[Set pass = false]
    G -- No --> I[Add marks to total]
    H --> I
    I --> J{More subjects?}
    J -- Yes --> F
    J -- No --> K[Calculate percentage]
    K --> L[Assign grade]
    L --> M[Update class total and topper]
    M --> N[Move to next student]
    N --> D
    D -- No --> O[Display student results]
    O --> P[Display class topper and average]
    P --> Q([End])
```

## 9. C Programming Concepts Used

-   **Variables and data types:** Store student count, marks, totals,
    percentages, grades, and pass/fail status.
-   **One-dimensional arrays:** Store totals, percentages, grades, and
    pass/fail values for students.
-   **Two-dimensional arrays:** Store marks for multiple students across
    five subjects.
-   **Nested `for` loops:** Process each student and each subject.
-   **`do-while` loop:** Repeat mark entry until a valid value from 0 to
    100 is entered.
-   **Conditional statements:** Assign grades, check pass/fail status,
    and validate student count and marks.
-   **Arithmetic operators:** Calculate totals, percentages, and the
    class average.
-   **Input/output:** Use `scanf()` to read values and `printf()` to
    display results.

## 10. Compilation and Execution

### Requirements

-   A C compiler such as GCC.
-   A terminal or command prompt.

### Windows (PowerShell)

Open the project folder in the terminal and compile:

``` powershell
gcc StudentResultAndGradeAnalyzer.c -o result
```

Run the program:

``` powershell
.\result.exe
```

### Linux / macOS

Compile:

``` bash
gcc StudentResultAndGradeAnalyzer.c -o result
```

Run:

``` bash
./result
```

## 11. Sample Test Cases

The following examples use the program's grading and passing rules. Run
them with your compiled program and compare the terminal output. The
expected output is shown below; add your own captured terminal output or
screenshot in the actual-output section after running each test.

### Test Case 1: Student passes

**Input**

``` text
Number of students: 1
Subject 1: 95
Subject 2: 90
Subject 3: 85
Subject 4: 90
Subject 5: 80
```

**Expected output**

``` text
========== STUDENT RESULTS ==========

Student 1
Total Marks: 440 / 500
Percentage: 88.00%
Grade: B
Result: PASS

========== CLASS REPORT ==========

Class Topper: Student 1
Topper Marks: 440 / 500
Class Average: 88.00%
```

**Actual output:** Run Test Case 1 and paste or attach the output
captured from your program here.

### Test Case 2: Student fails because one subject is below 35

**Input**

``` text
Number of students: 1
Subject 1: 90
Subject 2: 80
Subject 3: 30
Subject 4: 85
Subject 5: 75
```

**Expected output**

``` text
========== STUDENT RESULTS ==========

Student 1
Total Marks: 360 / 500
Percentage: 72.00%
Grade: C
Result: FAIL

========== CLASS REPORT ==========

Class Topper: Student 1
Topper Marks: 360 / 500
Class Average: 72.00%
```

**Actual output:** Run Test Case 2 and paste or attach the output
captured from your program here.

### Test Case 3: Invalid mark is rejected

**Input**

``` text
Number of students: 1
Subject 1: 120
```

**Expected behavior**

``` text
Invalid marks! Enter between 0 and 100.
```

The program should ask for Subject 1 again. Enter a valid mark to
continue.

**Actual output:** Run Test Case 3 and paste or attach the output
captured from your program here.

### Test Case 4: Multiple students and class average

**Input**

``` text
Number of students: 2

Student 1:
Subject 1: 80
Subject 2: 85
Subject 3: 90
Subject 4: 75
Subject 5: 70

Student 2:
Subject 1: 90
Subject 2: 95
Subject 3: 85
Subject 4: 90
Subject 5: 100
```

**Expected output**

``` text
Student 1
Total Marks: 400 / 500
Percentage: 80.00%
Grade: B
Result: PASS

Student 2
Total Marks: 460 / 500
Percentage: 92.00%
Grade: A
Result: PASS

========== CLASS REPORT ==========

Class Topper: Student 2
Topper Marks: 460 / 500
Class Average: 86.00%
```

**Actual output:** Run Test Case 4 and paste or attach the output
captured from your program here.

## 12. Conclusion

The Student Result and Grade Analyzer automates the process of
calculating student results across five subjects. It calculates totals
and percentages, assigns grades, checks subject-wise passing
requirements, identifies the class topper, and calculates the class
average.

The project demonstrates the use of fundamental C programming concepts,
including arrays, loops, conditional statements, arithmetic operations,
and input/output functions.

------------------------------------------------------------------------

**Project:** Student Result and Grade Analyzer\
**Language:** C\
**Source file:** `StudentResultAndGradeAnalyzer.c`
