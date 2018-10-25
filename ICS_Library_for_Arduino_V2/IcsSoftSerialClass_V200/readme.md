
# IcsSoftSerialClass for Arduino
---

Overview
�ߓ��Ȋw��ICS�@���Arduino��SoftSerial���瓮�������߂̃��C�u�����ł��B  
This library is for connecting a Kondo Kagaku ICS device from an Arudino Software serial port.

## Description
�ߓ��Ȋw���T�[�{���[�^���M�@��ICS�@���Arduino�œ��������߂̃��C�u�����ł��B  
This library is for connecting a Kondo Kagaku servo motor, receiver or other ICS device using Arudino.

�T�[�{���[�^�̈ʒu����(�|�W�V����)�R�}���h��X�g���b�`���̃p�����[�^�ύX��Arduino����ł���悤�ɂȂ�܂��B
 It enables servo motor position commands and parameter changes like for �gstretch�h to be performed from Arudino.

��M�@(KRR)�ɐڑ����邱�ƂŁA���M�@(KRC)����̃f�[�^���擾�ł��܂��B
By connecting to a receiver (KRR), data can also be acquired from a transmitter (KRC).

Arduino����� Software Serial��p���ĒʐM�����܂��B
Communications can be performed from Arudino using a Software serial port.

## Requirement
- Arduino Meag
Not all pins on the Mega and Mega 2560 support change interrupts, so only the following can be used for RX: 10, 11, 12, 13, 14, 15, 50, 51, 52, 53, A8 (62), A9 (63), A10 (64), A11 (65), A12 (66), A13 (67), A14 (68), A15 (69).

- Arduino Uno
Not all pins on the Leonardo and Micro support change interrupts, so only the following can be used for RX: 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

��	reference to (<https://www.arduino.cc/en/Reference/SoftwareSerial>)

## Usage
Arduino����A�N�Z�X�ł���IcsSoftSerialClass���g���ɂ�IcsClass��IcsBaceClass�������N�ł���悤�ɂ��Ă��������B
To use IcsHardSerialClass, which can be accessed from Arudino, make sure IcsClass�fs IcsBaseClass can be linked.

�܂��A KoCustomSoftSerial�������N���Ă��������B
Also make sure to link KoCustomSoftSerial.

���̃}�C�R�����g�������ꍇ�́AIcsBaceClass��h��������ƕ֗��ł��B
To use IcsHardSerialClass, which can be accessed from Arudino, make sure IcsClass�fs IcsBaseClass can be linked.

�ڂ����g�����ɂ��ẮA�z�z�t�H���_�̃}�j���A�����������������B
For details, refer to the manual in the folder provided.

## Licence
Copyright 2018 Kondo Kagaku co.,ltd.
[MIT](http://opensource.org/licenses/mit-license.php)
see to MIT_Licence.txt
or
Copyright 2018 Kondo Kagaku co.,ltd.
[LGPL 3.0](https://www.gnu.org/licenses/lgpl-3.0.html)
see to lgpl-3.0.txt
(use to KoCustomSoftSerial)

## Author
�ߓ��Ȋw�������
Kondo Kagaku co.,ltd.
T.Nobuhara
�ߓ��Ȋw�z�[���y�[�W:(<http://kondo-robot.com/>)
