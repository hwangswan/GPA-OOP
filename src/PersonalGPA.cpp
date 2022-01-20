/**
 * PersonalGPA.h implementation
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include"PersonalGPA.h"

/**
 * Constructor for PersonalGPA
 *
 */
PersonalGPA::PersonalGPA() {
  // Do nothing;
}

/**
 * Destructor for PersonalGPA
 *
 */
PersonalGPA::~PersonalGPA() {
  // Do nothing;
}

/**
 * Parameterised constructor
 *
 * @param  const std::vector<Subject>&
 */
PersonalGPA::PersonalGPA(
    const std::vector<Subject>& subjects) {
  for (const Subject& subject : subjects) {
    addSubject(subject);
  }
}

/**
 * Return total credits
 *
 * @return int
 */
int PersonalGPA::sumCredits() {
  return _sumCredits;
}

/**
 * Return sum grades.
 *
 * @return Grade
 */
Grade PersonalGPA::sumGrades() {
  return _sumGrades;
}

/**
 * Return GPA
 *
 * @return Grade
 */
Grade PersonalGPA::resultGPA() {
  return _resultGPA;
}

/**
 * Convert class to string vector.
 *
 * @return std::vector<std::string>
 */
std::vector<std::string> PersonalGPA::toStringVector() {
  std::vector<std::string> stringVector;

  stringVector.push_back("Overall");
  stringVector.push_back(std::to_string(_sumCredits));
  stringVector.push_back(_resultGPA.toString());
  stringVector.push_back(_resultGPA.to4Scale().toString());
  stringVector.push_back(_resultGPA.toAScale());

  return stringVector;
}

/**
 * Convert to vector of string vectors.
 *
 * @return std::vector<std::vector<std::string>>
 */
std::vector<std::vector<std::string>> PersonalGPA::toPassedVector() {
  std::vector<std::vector<std::string>> resultVector;

  for (const Subject& subject : _classesPassed) {
    resultVector.push_back(subject.toStringVector());
  }

  // Push overall.
  resultVector.push_back(toStringVector());

  return resultVector;
}

/**
 * Just like above, but for failed.
 *
 * @return std::vector<std::vector<std::string>>
 */
std::vector<std::vector<std::string>> PersonalGPA::toFailedVector() {
  std::vector<std::vector<std::string>> resultVector;

  for (const Subject& subject : _classesFailed) {
    resultVector.push_back(subject.toStringVector());
  }

  return resultVector;
}

/**
 * Return total classes.
 *
 * @return int
 *
 * @throw  std::runtime_error
 */
int PersonalGPA::getTotalClasses() {
  int totalClasses = _classesPassed.size() + _classesFailed.size();

  // Handling the situtation that no class added.
  if (0 == totalClasses) {
    throw std::runtime_error("No class was added.");
  }

  return totalClasses;
}

/**
 * Return total passed classes.
 *
 * @return int
 */
int PersonalGPA::getTotalClassesPassed() {
  return _classesPassed.size();
}

/**
 * Return total failed classes.
 *
 * @return int
 */
int PersonalGPA::getTotalClassesFailed() {
  return _classesFailed.size();
}

/**
 * Parse data into Personal
 *
 * @param  const std::vector<std::string>&
 *
 * @return std::shared_ptr<IPersonal>
 */
std::shared_ptr<PersonalGPA> PersonalGPA::parse(
    const std::vector<std::string>& input) {
  std::vector<Subject> subjects = Subject::parseSubjectVector(input.at(0));

  return std::make_shared<PersonalGPA>(subjects);
}

/**
 * Add a new subject.
 *
 * @param  const Subject&
 */
void PersonalGPA::addSubject(const Subject& subject) {
  // If not passed, then insert into failed list.
  if (!subject.passed()) {
    _classesFailed.insert(subject);
    return;
  }

  // Calculate new GPA.
  _sumCredits += subject.credit();
  _sumGrades += subject.grade() * subject.credit();
  _resultGPA = _sumGrades / (1.0 * _sumCredits);

  // Insert to passed list.
  _classesPassed.insert(subject);
}

