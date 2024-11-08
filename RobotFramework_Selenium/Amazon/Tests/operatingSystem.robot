*** Settings ***
Library    OperatingSystem
Suite Setup    Operating System Suite Setup
Suite Teardown    Operating System Suite Teardown

*** Variables ***
${Res_Dir}    Resources
${data_file}    data.txt
${data_file2}    data_2.txt
${txt2write}    "data file"

*** Test Cases ***
Operating System Basics
    [Documentation]    Basic test for Operating System library

    Log    Check directory
    Directory Should Exist    ${Res_Dir}
    Directory Should Not Be Empty    ${Res_Dir}
    Count Files In Directory    ${Res_Dir}

    Log    Delete existing data file
    ${file_exists} =   Run Keyword and Return Status    File Should Not Exist    ${Res_Dir}/${data_file}
    IF    ${file_exists} == ${FALSE}
         Remove File    ${Res_Dir}/${data_file}
         File Should Not Exist    ${Res_Dir}/${data_file}
    END

    Log    Create data file
    Touch    ${Res_Dir}/${data_file}
    File Should Exist    ${Res_Dir}/${data_file}
    File Should Be Empty    ${Res_Dir}/${data_file}
    Get File Size    ${Res_Dir}/${data_file}
    ${file} =    Get File    ${Res_Dir}/${data_file}
    Log    ${file}
    Should Be Empty    ${file}

    Log    Write to data file
    Append To File    ${Res_Dir}/${data_file}    ${txt2write}
    Get File Size    ${Res_Dir}/${data_file}
    ${file} =    Get File    ${Res_Dir}/${data_file}
    Log    ${file}
    Should Be True    ${file}==${txt2write}

    Log    Copy data file
    Copy File    ${Res_Dir}/${data_file}    ${Res_Dir}/${data_file2}
    File Should Exist    ${Res_Dir}/${data_file2}
    Get File Size    ${Res_Dir}/${data_file2}
    ${file} =    Get File    ${Res_Dir}/${data_file2}
    Log    ${file}
    Should Be True    ${file}==${txt2write}

*** Keywords ***
Operating System Suite Setup
    File Should Not Exist    ${Res_Dir}/${data_file2}

Operating System Suite Teardown
    Remove File    ${Res_Dir}/${data_file2}
