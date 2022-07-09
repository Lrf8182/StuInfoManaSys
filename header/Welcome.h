#pragma once

/**
 * @brief Program starting interface.
 * @return -0 Quit this system.
 *         -1 Print all students.
 *         -2 Add astudent.
 *         -3 Delete a student.
 *         -4 Search for a student.
 *         -5 Print specified students by score ranking.
*/
int welcome();
void option(int);