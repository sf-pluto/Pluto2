#ifndef INCLUDED_OBJECT_CONST_H
#define INCLUDED_OBJECT_CONST_H

namespace Object{
// �q�e���v���[�g�N���X�������
	// ��߁B�S�����s���ɒu�����Ď��s
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