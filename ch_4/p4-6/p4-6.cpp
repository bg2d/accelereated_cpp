#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0; // the length of the longest name

    // read and store all the students data.
    // Invariant: students contains all the student records read so far
    // max len contains the length of the logenst name in students
    while (read(cin, record)) {
        // find the length of the logest name
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // alphabetize the sudent records
    sort(students.begin(), students.end(), compare);

    // write the names and grades
    for (vector<Student_info>::size_type i = 0;
        i != students.size(); ++i) {
            // write the name, padded on the right to maxlen + 1 characters
            cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

            // compute and write the grade
            try {
                streamsize prec = cout.precision();
                cout << setprecision(3) << students[i].final_grade << setprecision(prec);
            } catch (domain_error e) {
                cout << e.what();
            }
            cout << endl;
        }

    return 0;
}
