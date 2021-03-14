/**
 * Subject APIs.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include"Subject.h"

/**
 * This function split a CSV line and read its data into a Subject struct.
 *
 * @param std::string
 * @return Subject
 */
Subject readSubject(std::string subjectLine) {
  Subject resultSubject;

  std::string determiner = ",";
  std::string token;

  size_t index, currentPoint; index = currentPoint = 0;

  while ((index = subjectLine.find(determiner)) != std::string::npos) {
    token = subjectLine.substr(0, index);

    if (token.length() > 0) {
      switch (currentPoint) {
        case 0:
          resultSubject.name = token;
          break;

	case 1:
	  resultSubject.credit = stoi(token);
	  break;
      }
    }

    ++currentPoint;
    subjectLine.erase(0, index + determiner.length());
  }

  // After reading, tokens left is the grade.
  resultSubject.grade       = stod(subjectLine);
  resultSubject.scale4Grade = convertGradeTo4Scale(resultSubject.grade);
  resultSubject.textGrade   = convertGradeToAScale(resultSubject.grade);

  return resultSubject;
}

/**
 * This function read a CSV file into vector of Subjects.
 *
 * @param  std::string
 * @return std::vector<Subject>
 */
std::vector<Subject> readSubjectsFromCSVFile(std::string fileName) {
  std::vector<Subject>subjects;

  std::ifstream fileStream(fileName, std::ios::in);
  std::string currentLine;

  while (std::getline(fileStream, currentLine))
    // Only push lines that have length > 0.
    if (currentLine.length() > 0) subjects.push_back(readSubject(currentLine));

  fileStream.close();

  return subjects;
}

/**
 * Convert grade to 4-scale.
 * (based on VNUHCM - University of Science Student Guide 2019).
 *
 * @param  double
 * @return double
 */
double convertGradeTo4Scale(double grade) {
  if (grade < 3.0) return 0.0;
  if (grade < 4.0) return 1.0;
  if (grade < 5.0) return 1.5;
  if (grade < 6.0) return 2.0;
  if (grade < 7.0) return 2.5;
  if (grade < 8.0) return 3.0;
  if (grade < 9.0) return 3.5;
  return 4.0;
}

/**
 * Convert grade to A-scale.
 * (based on VNUHCM - University of Science Student Guide 2019).
 *
 * @param  double
 * @return std::string
 */
std::string convertGradeToAScale(double grade) {
  if (grade < 3.0) return "F";
  if (grade < 4.0) return "D";
  if (grade < 5.0) return "D+";
  if (grade < 6.0) return "C";
  if (grade < 7.0) return "B";
  if (grade < 8.0) return "B+";
  if (grade < 9.0) return "A";
  return "A+";
}
