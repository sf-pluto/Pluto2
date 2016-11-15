#ifndef INCLUDED_OBJECT_CONST_H
#define INCLUDED_OBJECT_CONST_H

namespace Object{
// 子テンプレートクラスをらっぷ
	// やめ。全部実行時に置換して実行
class Const{
public:
	Const( float val ); 

	operator float(){
		return mValue;
	}
private:
	float mValue;
};

}

#endif //#ifndef INCLUDED_OBJECT_CONST_H