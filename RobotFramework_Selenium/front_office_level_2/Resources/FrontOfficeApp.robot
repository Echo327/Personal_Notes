*** Settings ***
Resource    PageObjects_FrontOffice/TopNav.robot
Resource    PageObjects_FrontOffice/LandingPage.robot
Resource    PageObjects_FrontOffice/Team.robot
Resource    PageObjects_FrontOffice/Contact.robot

*** Variables ***

*** Keywords ***
Go To "Landing Page"
    LandingPage.Open "Landing Page"

Check "Landing Page" Loaded
    LandingPage.Confirm Page Loaded

Open "Team"
    TopNav.Click on "Team"
    Team.Confirm Page Loaded

Check "Team" Page Content
    Team.Check Content

Open "Contact"
    TopNav.Click on "Contact"
    Contact.Confirm Page Loaded

Check "Contact" Page Content
    Contact.Check Content
