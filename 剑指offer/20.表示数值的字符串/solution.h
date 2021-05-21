/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-05-21 16:21:32
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class FloatPoint{
public:
	// @breif:      初始化浮点数分析对象构造函数
	// @param[in]:  [string&]input 需要识别的代码段
	// @return:
	FloatPoint(std::string& input) {
		_input_str = input;
		init();
	}

	// @breif:      初始化文法、初始化状态
	// @param[in]:
	// @return:     是否成功 0:成功 -1失败
	int init();

	// @breif:      获取下一个浮点数字
	// @param[out]:  [string&] 识别出来的浮点数字串
	// @return:     是否成功 0:成功 -1失败
	int getNextToken(std::string& token);

	// @breif:      判断字符是否为数字
	// @param[in]:  [char] 单个字符
	// @return:     true:为数字 false:不为数字
	bool isDigit(char ch);

	// @breif:      输出错误信息
	// @param[out]:  [std:;string&] 错误信息
	// @return:     是否成功 0:成功 -1失败
	int error_log(std::string& mess);


	// @breif:      拿到当前已经识别出来的浮点数串
	// @param[out]:  [std::string&] 当前串
	// @return:     是否成功 0:成功 -1失败
	int getCurToken(std::string& curToken);

	// @breif:      判断是否为数字、e/E、+/-、空格之外的字符
	// @param[in]:  [char] ch
	// @return:     是否成功 0:成功 -1失败
	bool isOther(char ch);

	// @breif:      获取下一个字符，先将字符指针加一，如果识别到了最后一个字符之后，则返回-1
	// @param[out]:  [char*] ch
	// @return:     是否成功 0:成功 -1失败
	int getChar(char* ch);

	// @breif:     恢复自动机状态
	// @param[out]:  [char*] ch
	// @return:     是否成功 0:成功 -1失败
	int restoreAutonmata();

	int getPtr() {
		return ptr;
	}

private:
	//状态转移关系；确定有限自动机转换图
	map<int, map<char, int> > _f;
	//当前状态
	int _state;
	//当前识别的结果
	std::string _curToken;
	//输入字符串
	std::string _input_str;
	//在识别串中的位置
	int ptr;
	//字符集
	set<char> all_char_set;
};

// @breif:      初始化文法、初始化状态
int FloatPoint::init() {
	int res = 0;
	//初始化文法
	_f[0]['+'] = 1;
	_f[0]['-'] = 1;
	_f[0]['d'] = 2;
	_f[0]['.'] = 10;
	_f[0][' '] = 0;
	_f[1]['d'] = 2;
	_f[1][' '] = 9;
    _f[1]['.'] = 10;
	_f[2]['d'] = 2;
	_f[2]['.'] = 3;
	_f[2]['e'] = 5;
	_f[2]['E'] = 5;
	_f[2]['o'] = 8;
	_f[2][' '] = 9;
	_f[3]['d'] = 4;
	_f[3]['o'] = 8;
    _f[3]['e'] = 5;
    _f[3]['E'] = 5;
	_f[3][' '] = 9;
	_f[4]['d'] = 4;
	_f[4]['e'] = 5;
	_f[4]['E'] = 5;
	_f[4]['o'] = 8;
	_f[4][' '] = 9;
	_f[5]['+'] = 6;
	_f[5]['-'] = 6;
	_f[5]['d'] = 7;
	_f[5]['o'] = 9;
	_f[5][' '] = 5;
	_f[6]['o'] = 9;
	_f[6]['d'] = 7;
	_f[6][' '] = 6;
    _f[6]['.'] = 10;
	_f[7]['d'] = 7;
	_f[7]['o'] = 8;
	_f[7][' '] = 9;
	_f[8][' '] = 8;
	_f[9][' '] = 9;
	_f[10]['o'] = 9;
	_f[10]['d'] = 4;

	//初始化当前状态
	_state = 0;

	//初始化已经识别的字符串
	_curToken = "";

	//在识别串中的位置，初始为-1
	ptr = -1;

	all_char_set.insert('e');
	all_char_set.insert('E');
	all_char_set.insert('+');
	all_char_set.insert('-');
	all_char_set.insert(' ');
	all_char_set.insert('.');
	return res;
}

// @breif:      获取下一个浮点数字
int FloatPoint::getNextToken(std::string& token) {
	int res = 0;
	int _input_len = _input_str.length();
	//最后一个字符为\0，不在字符集中，所以一定会进入到9或8状态
	while (ptr <= _input_len) {
		if (_state == 8 && ptr == _input_len) {
			res = getCurToken(token);
			restoreAutonmata();//恢复自动机为初始状态
			break;
		} else if(_state == 9) {
			res = error_log(token);
			restoreAutonmata();//恢复自动机为初始状态
			break;
		}

		char ch = '\0';
		res = getChar(&ch);

		//开始状态特殊处理， 非数字、加减号进入不了状态机
		if(_state == 0 && !isDigit(ch) && ch!='+' && ch!='-' && ch!='.' && ch!=' ') {
			return -1;
		}

		//获取下一个状态
		if (isDigit(ch)) {
			//数字，文法中没定义转移，则报错
			map<char, int>::iterator iter = _f[_state].find('d');
			if (iter != _f[_state].end()) {
				_state = iter->second;
				_curToken += ch;
			} else {
				_state = 9;
			}
		} else if(isOther(ch)) {
			//其他字符，如果没有定义则报错
			map<char, int>::iterator iter = _f[_state].find('o');
			if (iter != _f[_state].end()) {
				_state = iter->second;
				if (_state != 9 && _state != 8) {
					_curToken += ch;
				}
			} else {
				_state = 9;
			}
		} else {
			//不是数字，也不是其他字符，说明可能是.,'e','E',' ','+','-'
			map<char, int>::iterator iter = _f[_state].find(ch);
			if (iter != _f[_state].end()) {
				bool flag = false;
				if ((_state == 2 || _state == 4 || _state == 7 || _state == 3) && ch==' ') {
					int pp = ptr;
					//如果是最后一个空格
					int flag_tmp = true;
					while (++pp < _input_len) {
						if (_input_str[pp] != ' ') {
							flag_tmp = false;
						}
					}
					flag= flag_tmp;
				}
					//如果是最后一个空格则正确识别
				if (flag) {
					_state = 8;
					ptr=_input_len;
				} else {
					_state = iter->second;
				}
				_curToken += ch;
			} else {
				_state = 9;
			}
		}
	}

	return res;
}

// @breif:      判断字符是否为数字
bool FloatPoint::isDigit(char ch) {
	bool is_digit = false;
	if (ch >='0' && ch <='9') {
		is_digit = true;
	}
	return is_digit;
}

// @breif:      输出错误信息
int FloatPoint::error_log(std::string& mess){
	int res = -1;
	mess = "error";
	return res;
}


// @breif:      拿到当前已经识别出来的浮点数串
int FloatPoint::getCurToken(std::string& token) {
	int res = 0;
	token = _curToken;
	return res;
}

// @breif:      判断是否为数字、e/E、+/-、空格之外的字符
bool FloatPoint::isOther(char ch) {
	bool is_other = false;
	//不是数字，也不在字符集合中，则表示是其他字符
	if (!isDigit(ch)
	    && all_char_set.find(ch) == all_char_set.end()) {
		is_other = true;
	}
	return is_other;
}
// @breif:      获取下一个字符，先将字符指针加一，如果识别到了最后一个字符之后，则返回-1
int FloatPoint::getChar(char* ch) {
	int res=0;
	int _input_len = _input_str.length();
	++ptr;
	if (ptr >= _input_len) {
		res = -1;
	} else {
		*ch = _input_str[ptr];
	}
	return res;
}


// @breif:     恢复自动机状态
int FloatPoint::restoreAutonmata() {
	int res = 0;
	//当前状态
	_state = 0;
	//当前识别的结果
	_curToken = "";
	return res;
}

class Solution {
public:
	bool isNumber(string s) {
		bool res = false;
		FloatPoint float_point(s);
		string token = "";
		//正确识别、且扫描到结尾才返回则代表为数字串
		if (float_point.getNextToken(token) !=-1
		    && token!="error"
		    && float_point.getPtr() == s.length()) {
			res = true;
		}
		return res;
	}
};