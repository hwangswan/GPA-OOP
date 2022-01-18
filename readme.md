# GPA-OOP

Caculating my GPA, in an OOP way.

## Installation
- Make sure your C++ version >= C++17.
- `git clone`
- Compile using Makefile:
```
make
```

So simple, right?

## Running
### 1. Input format
- The input `.csv` file should looks like this:

  |course code|course credit|course grade|
  |:---------:|:-----------:|:----------:|
  |CSC10001|4|10
  |CSC10002|4|8.5
  |...|...|...

### 2. Command-line arguments
Given that the program has been compiled successfully to `<PROGRAM>.exe`, then:
- To calculate overall GPA:
  ```shell
  ./<PROGRAM> <GRADE_FILE.csv> --gpa
  ```
- To calculate GPA of courses start with a prefix:
  ```shell
  ./<PROGRAM> <GRADE_FILE.csv> --specific <SPECIFIC_COURSES.txt>
  ```

  `<SPECIFIC_COURSES.txt>` content should looks like this:
  ```
  course1prefix
  course2prefix
  course3prefix

  (notice that if you use full course code, then only one course added,
  using a prefix would choose every course have `courseprefix` as a prefix).
  ```
- To calculate GPA but ignore some courses defines inside
  `<IGNORED_COURSES.txt>`:
  ```shell
  ./<PROGRAM> <GRADE_FILE.csv> --ignore <IGNORED_COURSES.txt>
  ```

  `IGNORED_COURSES.txt` content should looks like this:
  ```
  course1code
  course2code
  course3code

  (notice that this command using course code, not prefix. To ignore courses
  with a same prefix, using --specific without a prefix).
  ```
- Export to `.csv` format:
  ```shell
  ./<PROGRAM> <GRADE_FILE.csv>
    [--gpa /
     --specific <SPECIFIC_COURSES.txt> /
     --ignore <IGNORED_COURSES.txt>] --csv
  ```

### 3. Shell scripts
Example commands are in `run.sh.example`

### 4. Custom textart
- `data/textart.txt` stores the textart file. Modify it with your own textart.

## Attention!
1. Default grade scale is 10.
2. 4-scale and A-scale are based on [VNUHCM -
  University of Science Student Guide 2020-21](https://www.hcmus.edu.vn/component/content/article/124-cong-tac-sinh-vien/thong-tin-danh-cho-tan-sinh-vien/3323-so-tay-sinh-vien-nam-hoc-2020-2021?Itemid=437)
