#include <iostream>
#include <iomanip>

// Константи програми ( Варіант 3)

const int    STUDENT_COUNT   = 7;      // Масив із 7 елементів
const double HONOR_THRESHOLD = 90.0;   // Поріг для студента-відмінника
const int    TARGET_COURSE   = 2;      // Цільовий курс для другого підзавдання


// Пункт 3: Опис перелічувального типу (enum)

enum StudentName
{
    DMYTRO,
    IVAN,
    OLEKSIY,
    ANNA,
    MAKSYM,
    OLHA,
    DENYS
};

// Текстовий масив для коректного виведення імен з enum у консоль
const char* const STUDENT_NAMES_STR[STUDENT_COUNT] = {
    "Dmytro", "Ivan", "Oleksiy", "Anna", "Maksym", "Olha", "Denys"
};

// Пункт 1: Опис пойменованих типів (структур)

// Структура для завдання 3.1: Ім'я (enum), Середній бал (double), Музика (bool)
struct StudentMusic
{
    StudentName name;
    double      dGpa;
    bool        bPlaysMusic;
};

// Структура для завдання 3.2: Ім'я (enum), Курс (int), Стипендія (bool)
struct StudentGrant
{
    StudentName name;
    int         nCourse;
    bool        bHasScholarship;
};

// Завдання 3.1: Розрахунок відсотка відмінників, що займаються музикою

void executeSubtask1()
{
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    std::cout << "\n             PART 1: HONOR STUDENTS ENGAGED IN MUSIC (TABLE 22, VARIANT 3)\n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    // Пункт 4: Опис та ініціювання окремих базових масивів
    StudentName arrNames[STUDENT_COUNT] = {
        DMYTRO, IVAN, OLEKSIY, ANNA, MAKSYM, OLHA, DENYS
    };
    double arrGpa[STUDENT_COUNT] = {
        94.5, 82.0, 91.0, 88.5, 96.0, 75.5, 90.5
    };
    bool arrMusic[STUDENT_COUNT] = {
        true, false, true, false, false, true, true
    };

    // Пункт 2: Масив структур із 7 елементів
    StudentMusic arrStudents[STUDENT_COUNT];

    // Пункт 5: Ініціювання масиву структур даними з базових масивів
    for (int i = 0; i < STUDENT_COUNT; i++)
    {
        arrStudents[i].name        = arrNames[i];
        arrStudents[i].dGpa        = arrGpa[i];
        arrStudents[i].bPlaysMusic = arrMusic[i];
    }

    // Виведення бази даних
    std::cout << "----------------------------------------------------------\n";
    std::cout << "| "  << std::left       << std::setw(4)  << "No"
              << "| "                     << std::setw(14) << "Name (enum)"
              << "| "  << std::right      << std::setw(15) << "GPA (real)"
              << " | " << std::left       << std::setw(15) << "Plays Music"
              << "|\n";
    std::cout << "----------------------------------------------------------\n";

    for (int i = 0; i < STUDENT_COUNT; i++)
    {
        std::cout << "| "  << std::left                << std::setw(4)  << (i + 1)
                  << "| "                              << std::setw(14) << STUDENT_NAMES_STR[arrStudents[i].name]
                  << "| "  << std::right << std::fixed << std::setprecision(1) << std::setw(15) << arrStudents[i].dGpa
                  << " | " << std::left                << std::setw(15) << (arrStudents[i].bPlaysMusic ? "Yes (true)" : "No (false)")
                  << "|\n";
    }
    std::cout << "----------------------------------------------------------\n\n";

    // Пункт 6: Обробка масиву структур
    int nHonorCount      = 0;
    int nHonorMusicCount = 0;

    for (int i = 0; i < STUDENT_COUNT; i++)
    {
        if (arrStudents[i].dGpa >= HONOR_THRESHOLD)
        {
            nHonorCount++;
            if (arrStudents[i].bPlaysMusic)
            {
                nHonorMusicCount++;
            }
        }
    }

    std::cout << "Statistical Summary (Threshold GPA >= " << HONOR_THRESHOLD << "):\n"; //Пороговий середній бал
    std::cout << "  - Total students in database:       " << STUDENT_COUNT << "\n";     //Всього студентів у базі
    std::cout << "  - Honor students count:             " << nHonorCount << "\n";       //Кількість учнів-відмінників
    std::cout << "  - Honor students playing music:     " << nHonorMusicCount << "\n";  //Кількість учнів-відмінників,
                                                                                        //що займаються музикою

    if (nHonorCount > 0)
    {
        double dPercentGroup = (static_cast<double>(nHonorMusicCount) / nHonorCount) * 100.0;
        double dPercentTotal = (static_cast<double>(nHonorMusicCount) / STUDENT_COUNT) * 100.0;

        std::cout << "  - Percentage (among honor students): " << std::fixed << std::setprecision(2)
                  << dPercentGroup << " %\n";
        std::cout << "  - Percentage (among total class):    " << std::fixed << std::setprecision(2)
                  << dPercentTotal << " %\n\n";
    }
    else
    {
        std::cout << "  - No honor students found in the dataset.\n\n";
    }
}


// Завдання 3.2: Розрахунок відсотка другокурсників без стипендії

void executeSubtask2()
{
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    std::cout << "\n          PART 2: SECOND-YEAR STUDENTS WITHOUT SCHOLARSHIP (TABLE 22, VARIANT 3)\n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    // Пункт 4: Опис та ініціювання окремих базових масивів
    StudentName arrNames[STUDENT_COUNT] = {
        DMYTRO, IVAN, OLEKSIY, ANNA, MAKSYM, OLHA, DENYS
    };
    int arrCourses[STUDENT_COUNT] = {
        1, 2, 2, 3, 2, 4, 2
    };
    bool arrGrants[STUDENT_COUNT] = {
        true, false, true, true, false, true, true
    };

    // Пункт 2: Масив структур із 7 елементів
    StudentGrant arrStudents[STUDENT_COUNT];

    // Пункт 5: Ініціювання масиву структур
    for (int i = 0; i < STUDENT_COUNT; i++)
    {
        arrStudents[i].name            = arrNames[i];
        arrStudents[i].nCourse         = arrCourses[i];
        arrStudents[i].bHasScholarship = arrGrants[i];
    }

    // Виведення таблиці
    std::cout << "----------------------------------------------------------\n";
    std::cout << "| "  << std::left  << std::setw(4)  << "No"
              << "| "                << std::setw(14) << "Name (enum)"
              << "| "  << std::right << std::setw(15) << "Course (int)"
              << " | " << std::left  << std::setw(15) << "Scholarship"
              << "|\n";
    std::cout << "----------------------------------------------------------\n";

    for (int i = 0; i < STUDENT_COUNT; i++)
    {
        std::cout << "| "  << std::left  << std::setw(4)  << (i + 1)
                  << "| "                << std::setw(14) << STUDENT_NAMES_STR[arrStudents[i].name]
                  << "| "  << std::right << std::setw(15) << arrStudents[i].nCourse
                  << " | " << std::left  << std::setw(15) << (arrStudents[i].bHasScholarship ? "Yes (true)" : "No (false)")
                  << "|\n";
    }
    std::cout << "----------------------------------------------------------\n\n";

    // Пункт 6: Обробка масиву структур
    int nCourse2Count   = 0;
    int nNoScholarship2 = 0;

    for (int i = 0; i < STUDENT_COUNT; i++)
    {
        if (arrStudents[i].nCourse == TARGET_COURSE)
        {
            nCourse2Count++;
            if (!arrStudents[i].bHasScholarship)
            {
                nNoScholarship2++;
            }
        }
    }

    std::cout << "Statistical Summary (Target Course = "  << TARGET_COURSE << "):\n";
    std::cout << "  - Total students in database:       " << STUDENT_COUNT << "\n";
    std::cout << "  - 2nd-year students count:          " << nCourse2Count << "\n";
    std::cout << "  - 2nd-year without scholarship:     " << nNoScholarship2 << "\n";

    if (nCourse2Count > 0)
    {
        double dPercentCourse2 = (static_cast<double>(nNoScholarship2) / nCourse2Count) * 100.0;
        double dPercentTotal   = (static_cast<double>(nNoScholarship2) / STUDENT_COUNT) * 100.0;

        std::cout << "  - Percentage (among 2nd-year):       " << std::fixed << std::setprecision(2)
                  << dPercentCourse2 << " %\n";
        std::cout << "  - Percentage (among total class):    " << std::fixed << std::setprecision(2)
                  << dPercentTotal << " %\n\n";
    }
    else
    {
        std::cout << "  - No 2nd-year students found in the dataset.\n\n";
    }
}

// Головна функція main

int main()
{
    executeSubtask1();
    executeSubtask2();

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    std::cout << "\n                      Laboratory work 2.2 completed successfully.\n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    return 0;
}
