*** Settings ***
Documentation       This is some basic info about the whole suite.
Library             SeleniumLibrary     timeout=0:00:10
Resource            ../Resources/common.robot
Resource            ../Resources/crmApp.robot

# To run the script:
# robot -d .\Results\ .\Tests\crm.robot

Test Setup          Begin Web Test
Test Teardown       End Web Test

*** Variables ***
${BROWSER}          edge
${TEST_URL}         https://automationplayground.com/crm/
${VALID_EMAIL}      admin@robotframeworktutorial.com
${VALID_PASSWORD}   qwe
&{USER_DATA}    EmailAddress=janedoe@gmail.com    FirstName=Jane    LastName=Doe
...             City=Dallas    StateOrRegion=TX    gender=female
...             name=promos-name

*** Test Cases ***
Should be able to add a new customer
    [Documentation]     This is some basic info about the test
    [Tags]              1006  Smoke  Contacts
    Log    Starting Test Case

    Log    Go to Homepage
    crmApp.Go To "Home" Page

    Log    Login with valid credentials
    crmApp.Login With Credentials    ${VALID_EMAIL}    ${VALID_PASSWORD}

    Log    Add Customer
    crmApp.Add Customer    EmailAddress=${USER_DATA}[EmailAddress]    FirstName=${USER_DATA}[FirstName]    LastName=${USER_DATA}[LastName]
    ...                    City=${USER_DATA}[City]   StateOrRegion=${USER_DATA}[StateOrRegion]    gender=${USER_DATA}[gender]
    ...                    name=${USER_DATA}[name]

    Log    Log Out
    crmApp.Sign Out

*** Keywords ***

