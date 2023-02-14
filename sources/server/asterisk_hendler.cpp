#include "asterisk_hendler.hpp"

std::unordered_map<std::string_view, std::vector<std::string>>
    AsteriskHendler::table = {
        {"school",
         {
             "id",
             "full_name",
             "short_name",
             "start_date",
         }                                               },
        {"user",
         {
             "id",
             "login",
             "password",
             "name",
             "surname",
             "role_id",
             "school_id",
         }                                               },
        {"role",
         {
             "id",
             "name",
         }                                               },
        {"grade",
         {
             "id",
             "name",
             "head_id",
         }                                               },
        {"grade_student",
         {
             "id",
             "grade_id",
             "student_id",
         }                                               },
        {"group",
         {
             "id",
             "name",
             "grade_id",
         }                                               },
        {"group_student",
         {
             "id",
             "group_id",
             "student_id",
         }                                               },
        {"lesson",
         {
             "id",
             "theme_id",
             "date_val",
             "journal_table_id",
             "homework",
             "control",
         }                                               },
        {"journal_table",
         {
             "id",
             "teacher_id",
             "methodist_id",
             "is_group",
             "group_id",
             "subject_id",
             "plan_id",
             "head_id",
             "schedule",
         }                                               },
        {"subject",
         {
             "id",
             "name",
         }                                               },
        {"mark",
         {
             "id",
             "mark_value",
             "student_id",
             "lesson_id",
             "journal_table_id",
         }                                               },
        {"plan",
         {
             "id",
             "subject_id",
             "name",
             "url",
         }                                               },
        {"theme",
         {
             "id",
             "plan_id",
             "name",
             "hour_count",
         }                                               },
        {"file",
         {
             "id",
             "num",
         }                                               },
        {"holiday",       {"id", "school_id", "date_val"}}
};
