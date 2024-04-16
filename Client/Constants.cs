﻿namespace Client
{
    public class Constants
    {
        public const string APP_NAME = "Game Caro";
        public static int BUTTON_WIDTH = 20;
        public static int BUTTON_HEIGHT = 20;
        public static int BOARD_SIZE = 16;

        public static int OPCODE_SIZE = 1;
        public static int LENGTH_SIZE = 2;
        public static int LOCATION_SIZE = 1;

        public static string IP = "127.0.0.1";
        public static int port = 5500;
        public static int BUFFER_SIZE = 10240;

        public static int COOL_DOWN_STEP = 100;
        public static int COOL_DOWN_TIME = 10000;
        public static int COOL_DOWN_INTERVAL = 100;

        public const int FORM_MAIN = 0;
        public const int FORM_PLAY = 1;
        public const int FORM_ACCOUNT = 2;
        public const int FORM_HISTORY = 3;
        public const int FORM_PLAY_WITH_SERVER = 4;
        public const int FORM_PASSWORD = 5;

        public const int TURN_O = 1;
        public const int TURN_X = 2;

        ///Opcode///
        public const byte OPCODE_FILE = 0;
        public const byte OPCODE_FILE_DATA = 1;
        public const byte OPCODE_FILE_ERROR = 2;

        public const byte OPCODE_SIGN_UP = 10;
        public const byte OPCODE_SIGN_UP_SUCESS = 11;
        public const byte OPCODE_SIGN_UP_DUPLICATED_USERNAME = 12;
        public const byte OPCODE_SIGN_UP_DIFFERENT_REPASSWORD = 13;
        public const byte OPCODE_SIGN_UP_INVALID_USERNAME = 14;
        public const byte OPCODE_SIGN_UP_INVALID_PASSWORD = 15;
        public const byte OPCODE_SIGN_UP_UNKNOWN_ERROR = 19;

        public const byte OPCODE_SIGN_IN = 20;
        public const byte OPCODE_SIGN_IN_SUCESS = 21;
        public const byte OPCODE_SIGN_IN_ALREADY_LOGGED_IN = 22;
        public const byte OPCODE_SIGN_IN_USERNAME_NOT_FOUND = 23;
        public const byte OPCODE_SIGN_IN_INVALID_USERNAME = 24;
        public const byte OPCODE_SIGN_IN_INVALID_PASSWORD = 25;
        public const byte OPCODE_SIGN_IN_WRONG_PASSWORD = 26;
        public const byte OPCODE_SIGN_IN_UNKNOWN_ERROR = 29;

        public const byte OPCODE_SIGN_OUT = 30;
        public const byte OPCODE_SIGN_OUT_SUCCESS = 31;
        public const byte OPCODE_SIGN_OUT_NOT_LOGGED_IN = 32;

        public const byte OPCODE_INFO = 40;
        public const byte OPCODE_INFO_REPLY = 41;

        public const byte OPCODE_LIST = 50;
        public const byte OPCODE_LIST_REPLY = 51;

        public const byte OPCODE_CHALLENGE = 60;
        public const byte OPCODE_CHALLENGE_ACCEPT = 61;
        public const byte OPCODE_CHALLENGE_REFUSE = 62;
        public const byte OPCODE_CHALLENGE_INVALID_RANK = 63;
        public const byte OPCODE_CHALLENGE_BUSY = 64;
        public const byte OPCODE_CHALLENGE_NOT_FOUND = 65;

        public const byte OPCODE_CHALLENGE_WITH_SERVER = 70;
        public const byte OPCODE_CHALLENGE_WITH_SERVER_PLAY = 71;

        public const byte OPCODE_PLAY = 80;
        public const byte OPCODE_PLAY_OPPONENT = 81;
        public const byte OPCODE_PLAY_INVALID_CORDINATE = 82;
        public const byte OPCODE_PLAY_INVALID_TURN = 83;

        public const byte OPCODE_PLAY_WITH_SERVER = 90;
        public const byte OPCODE_PLAY_REPLY_SERVER = 91;
        public const byte OPCODE_PLAY_INVALID_CORDINATE_SERVER = 92;
        public const byte OPCODE_PLAY_INVALID_TURN_SERVER = 93;

        public const byte OPCODE_RESULT = 100;
        public const byte OPCODE_SURRENDER = 101;
        public const byte OPCODE_SURRENDER_WITH_SERVER = 102;
        public const byte OPCODE_TIMER_DRAW = 103;
        public const byte OPCODE_TIMER_DRAW_WITH_SERVER = 104;

        public const byte OPCODE_HISTORY = 110;
        public const byte OPCODE_HISTORY_REPLY = 111;

        public const byte OPCODE_CHANGE_PASSWORD = 120;
        public const byte OPCODE_CHANGE_PASSWORD_SUCCESS = 121;
        public const byte OPCODE_CHANGE_PASSWORD_WRONG = 122;
        public const byte OPCODE_CHANGE_DIFFERENT_NEWPASSWORD = 123;
        public const byte OPCODE_CHANGE_PASSWORD_INVALID = 124;
        public const byte OPCODE_CHANGE_PASSWORD_OLDNEW = 125;
    }
}
