# Introduction

In this section, we are concerned with setting up our computer, and using the development tools needed for this course.

The choice of tool is discussed so that by the end of this section, as well as learning to use the tools, hopefully you will also begin to be able to *select appropriate software development tools, techniques and environments to aid the implementation of simple software.*

## Aims:

The aims of this section are as follows:

* Install the development tools
* Building and running some code
* Debugging 
* Version control to manage changes
* Appreciate the rationale for using specific tools

## Table of Contents

## Choice of Software

This course is aimed at beginners, and uses Visual Studio Community Edition running on Microsoft Windows 10 or 11 as a host operating system. Screenshots will differ from the Mac version of Visual Studio. The focus is on programming however, so beyond initial setup, it will make little difference. Some material has been provided to support setting up and use of Visual Studio Code (for those on Mac OS or Linux).

> Subsequent modules will also be using Visual Studio (for Windows). If you do venture in a different direction, please ensure you are comfortable using Visual Studio (it is on all our lab machines).

Part of computer science is choosing the right tools. Below is a description of *some* of the choices available to us. This is a small subset from the tools we sometimes use, and many others are available.

| Item | Name | Description |
| - | - | - |
| 1. | **I**ntegrated **D**evelopment **E**nvironment (**IDE**) | This is a software tool that allows us to write source code, build executable programs and test |
| | [Visual Studio](https://visualstudio.microsoft.com/downloads/) | A complete developer tool that supports multiple languages and frameworks. It is suitable for beginners and experts. It is available for MS Windows and Mac OS (although Mac support is being dropped). Developers can select different options depending on needs. Visual Studio can occupy a considerable amount of disk space, especially if support for a lot of frameworks is needed. It also supports a plug-in architecture to allow it to be extended. Visual studio community edition is free for individuals. |
| | [Visual Studio Code](https://code.visualstudio.com/) | This is a free and and open-source cross-platform text editor with a rich plug-in ecosystem. Increasingly it is used as a full IDE. Configuration is not as simple as Visual Studio, and may not always be the best choice for beginners. However, it is available for Windows, Linux (inc. Raspberry Pi), Mac OS and [Web](https://vscode.dev/) |
| 2. Build Tools | [Microsoft C/C++ Compiler](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022) | This is the tool that converts your code into binary code that a computer understands. The Microsoft Compiler can be installed as part of Visual Studio, or as a separate standalone package. Again, free for individual use. It is maybe important to note that an IDE and build tools are separate entities. The IDE allows to the user to edit software source code and interact with the built tools in a more user friendly way. |
| | open source (gcc) | A popular option for those who need to build software with maximum compatibility with Linux. A popular system is [msys2](https://www.msys2.org/) which includes support for multiple languages. This may not be the best choice for beginners, and does come with some additional complexity. It is of course free. Another option is to use [WSL2](https://learn.microsoft.com/windows/wsl/install), which is now part of Microsoft Windows. This gets you a full virtual Linux based environment capable of running both command-line and graphical apps. |

Beyond this course, choice of tools can be confusing. The term "curse of choice" is sometimes used to describe this. Often it will depend on what others around you are using and the support that provides.

Increasingly, software is written to execute in a "headless" environment, that is, one without a screen, mouse or keyboard. This includes the following use cases:

* Continuous Integration - tools used to verify, validate and even deploy software as it is built.

* Embedded / Internet of Things (IoT) - There is a vast market of electronic devices running software, spanning many sectors, including consumer devices, kiosks and commercial jet dashboards and control systems. Such software runs on a diverse variety of hardware, often with limited computing resources. To maximize use of resources, much of this is written in C or C++.

* Server Side Code - The World Wide Web is, in part, built from a vast interconnected network of computers, known as servers. When a resource is requested (such as a web page), code will run on that machine. 

There may be times when a developer only wishes to remotely connect to such a system to modify / debug some software. Sometimes they may choose to only use a text editor and a compiler on the live system. This can actually be simpler, *once* you know how of course.

Many open source tools are designed to be build from the *command line*, and do not require the installation of an IDE. This can become complex, and may use tools such as `make` or `cmake` to manage this in a scripted environment. It is often the case that an IDE will also leverage such tools, but offers are more user friendly experience.

Choice of tool depends on experience, environment, budget, language and available expertise. Personal preference can be a factor, but equally, so can company culture and expectation to work with others. 

### Some Perspective 

We want to keep things simple to we can focus on learning to program. Finding the perfect tool set can easily become a distraction. We would encourage students to explore the different options out there. However, this should not be at the expense of working on the assessed aspects of this course.

> Remember - we don't want to spend all our time sharpening our pencils. We also need to write something!


