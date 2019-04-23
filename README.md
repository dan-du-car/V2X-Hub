| CicleCI Build Status | Sonar Code Quality |
|----------------------|---------------------|
[![CircleCI](https://circleci.com/gh/usdot-fhwa-OPS/V2X-Hub.svg?style=svg)](https://circleci.com/gh/usdot-fhwa-OPS/V2X-Hub) | [![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=usdot-fhwa-ops_V2X-Hub&metric=alert_status)](https://sonarcloud.io/dashboard?id=usdot-fhwa-ops_V2X-Hub) |

# Overview
In order to bring infrastructure components into the Connected Vehicle architecture, you need software that will facilitate the exchange of data in a format that can be understood by both vehicles and infrastructure devices The V2X Hub, takes in data from vehicles via Basic Safety Messages (BSM) in a Society of Automotive Engineers (SAE) standard format and translates the data to a National Transportation Communications for ITS Protocol (NTCIP) that infrastructure components can understand.  And vice versa.   It translates Signal Phase and Timing (SPaT) data from NTCIP to SAE and sends it to the Roadside Unit (RSU) for broadcast to mobile devices, including vehicles. 

V2X Hub is a message handler that acts as a translator and data aggregator/disseminator for infrastructure components of a connected vehicle deployment. 

V2X Hub was developed to support jurisdictions in deploying Vehicle-to-Infrastructure (V2I) technology by reducing integration efforts and issues.
* V2X Hub is a software platform that enables connected vehicles to talk to existing traffic management hardware and systems, such as traffic signal controllers, Transportation Management Centers, pedestrian and vehicle detection systems, road weather sensors, and dynamic message signs.
* V2X Hub simplifies integration by translating communication between different standards and protocols.
* Using a modular design, software plugins enable efficient connections to new hardware, custom connections to Transportation Management Centers, and Connected Vehicle (CV) Safety Apps to run on roadside equipment.

The V2X Hub system reduces time needed to create and deploy a roadside based V2X system.  The V2X Hub system contains a suite of plugins that are built to handle specific functionality.  The output of these plugins will vary, but any plugin that communicates externally will produce a message from the J2735-2016 messages set.  Plugins can request to receive data that is being produced by other plugins in the system.  For example, a location plugin can create a location message that is then received by the MAP plugin for use it in its processing.  Below are a list of plugins and the messages they produce that are included in the V2X Hub system.

* CSW Plugin – The Curve Speed Warning Plugin will monitor J2735 BSM messages at a curve, and send a message to a dynamic message sign when it detects that a vehicle is approaching a curve too fast.  The CSW plugin also produces a J2735 TIM message containing the approach zones for the curve to be used by a CSW in-vehicle CV application.
* DMS Plugin – The Dynamic Message Sign (DMS) Plugin will receive messages from other plugins and translate the information to NTCIP 1203 for display on a DMS.
* MAP Plugin – Produces intersection geometry in J2735 MAP format.
* SPAT Plugin – Communicates with a traffic signal controller (TSC) using NTCIP 1202, and creates a J2735 SPaT Message.
* DSRC Immediate Forward Plugin – Sends all J2735 traffic to the 4.1 RSU for transmission out the DSRC radio.
* Message Receiver Plugin – Receives all J2735 traffic incoming from the 4.1 RSU for consumption by other V2X Hub plugins.
* Location Plugin – Communicates with GPS devices producing location information and optionally the NMEA GP* sentences for the V2X Hub system. 
* RTCM Plugin – Communicates with a NTRIP network to create J2735 RTCM position correction messages.

V2X Hub is a communication, computation, and processing platform for V2I applications, and providing the functions listed below.

* Message handling across multiple interfaces using SAE J2735 messages:
	* Integrating data from multiple sources and compiling messages for delivery to vehicles and nomadic devices via multiple communication methods.
	* Obtaining and aggregating data from multiple vehicles and nomadic devices, and sending to the Transportation Management Entity.
        * Distribution of Traveler Information Messages (TIM) to local vehicles and devices.
* Examples of local infrastructure-based computation and processing:
	* Local computation of recommended speeds and stopping distances using real time weather and road condition data for crash imminent V2I safety scenarios such as Reduced Speed (Work Zone) Warning and Spot Weather Information Warning.
	* Aggregation of vehicle weather data for efficient communication to Transportation Management Entity for weather-responsive traffic management.
	* Multi-Modal Intelligent Traffic Signal Systems (MMITSS) “intersection level” functions including J2735 Intersection Geometry (MAP) and J2735 Signal Phase and Timing (SPaT) broadcast manager, equipped vehicle tracker, priority request server, and interface to traffic signal controller.


## Security and Passwords
V2X Hub is middleware that runs on Linux Ubuntu 16.04 LTS or Ubuntu 18.04 LTS with future versions on Ubuntu 18.04 LTS. It is recommended that appropriate security and firewall settings be used on the computer running Linux, including conforming to your agency's security best practices and IT protocols.

For configuration and maintenance, the V2X Hub software includes an Administration Portal that runs in a web browser on the host device. The default Username for accessing this Administration Portal is v2iadmin and the default password is V2iHub#123. It is strongly recommended that the v2iadmin password be changed with the first login to the Administration Portal via the menu on the left. Passwords must be a minimum of 8 characters, with at least 1 number, 1 uppercase letter, 1 lowercase, and 1 special character.  Additional users can be created using the Administration Portal by selecting Manage Users from the left menu.  While managing users, you can add new users and delete the default user v2iadmin.  If you want to delete the v2iadmin default user, It is recommended that you create a new user with admin privileges, login as that user, then delete the v2iadmin default user.


## License information
Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0 Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


## System Requirements
The V2X Hub software can run on most Linux based computers with Pentium core processers, with at least two gigabytes of RAM and at least 64GB of drive space. Performance of the software will be based on the computing power and available RAM in the system.  The project was developed and tested on a machine with a core i3 processor, 4GB of memory, 64GB of hard drive space, running Ubuntu 16.04 LTS.

The dependencies for Ubuntu 16.04 can be found in the [Ubuntu 16.04 Requirements Document](docs/Ubuntu 16.04 Requirements.md)

The dependencies for Ubuntu 18.04 can be found in the [Ubuntu 18.04 Requirements Document](docs/Ubuntu 18.04 Requirements.md)


## Installation and Setup
The installation and setup instructions can be found in the [Installation and Setup Guide](docs/Installation and Setup.md)

## Contribution
Welcome to the V2X-Hub contributing guide. Please read this guide to learn about our development process, how to propose pull requests and improvements, and how to build and test your changes to this project. [V2X-Hub Contributing Guide](Contributing.md) 

## Code of Conduct 
Please read our [V2X-Hub Code of Conduct](Code_of_Conduct.md) which outlines our expectations for participants within the V2X-Hub community, as well as steps to reporting unacceptable behavior. We are committed to providing a welcoming and inspiring community for all and expect our code of conduct to be honored. Anyone who violates this code of conduct may be banned from the community.

## Attribution
The development team would like to acknowledge the people who have made direct contributions to the design and code in this repository. [V2X-Hub Attribution](ATTRIBUTION.txt) 
