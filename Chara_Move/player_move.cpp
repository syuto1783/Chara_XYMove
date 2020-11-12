//**************************************************************
//		HEW2020�@prototype��
//		����A�l�@�L�����N�^�[�ړ�
//		2020/11/11
//		�u���̏����ǁ[��[���ƁH�݂����Ȃ̂��������[�ĂˁI�v
//**************************************************************

//�萔��`
#define JUMP_POWER 8		//�W�����v�̔n�͂��u�W�v�ɐݒ�
#define DEFAULT_Y 30		//�������ɒ��n����Y�����W���u�R�O�v�ɐݒ�

//�C���N���[�h
#include <stdio.h>
#include <Windows.h>

//�ϐ��錾
int block_x = 0;
int block_y = 0;

//���C�������i����main�֐������ǊF�̃v���O�����ƍ��̂����鎞�͊֐������܂Ђ�I�I�j
int main(void)
{
	//�v���C���[�i��l���j�̍\����
	struct PLAYER
	{
		int y = 30;				//Y���̏����ʒu���u�R�O�v�ɐݒ�
		int x = 0;				//X���̏����ʒu���u�O�v�ɐݒ�
		int foot_markX = 0;		//�L������X���ɓ����������ɔ������鑫�Ղ������ׂ̕ϐ�
		int foot_markY = 0;		//�L������Y���ɓ����������ɔ������鑫�Ղ������ׂ̕ϐ�
		int jump = 0;			//�L�����̃W�����v�ϐ��B��{�́u�O�v�ɐݒ�
		int jump_flag;			//�W�����v�̃t���O����̂��߂̕ϐ�
	};
	struct PLAYER player;

	/*�y�萔�́uJUMP�QPOWER�v�ƕϐ��́ujump�v�𕪂��Ă闝�R�z

		��{�I�ȃW�����v�̔n�͂�ݒ肵�Ă������ō��㉽������̃A�C�e����
		�ʏ�̃W�����v��荂���Ȃ�����A�Ⴍ�Ȃ�����ƕϐ��̐��������̏�����
		���ő�����邾���ŁA�ϐ��̒l�̓h��ւ��o�O�𖳂����ׁA���l�����o�邩�炾���
	*/

	//�J�[�\���ʒu�̐ݒ�
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;

	//���C�����[�v�����iWhile���Ɣėp�����������Ȃ猾���ĂˁI�j
	while (1)
	{
		//���삷��L�����̍��W�𑫐Տ����ϐ��ɃZ�b�g
		player.foot_markX = player.x;
		player.foot_markY = player.y;

		//���͏��u
		//�W�����v�iSPACE�j
		if (GetAsyncKeyState(VK_SPACE) && !player.jump_flag) {
			player.jump = -JUMP_POWER;
			player.jump_flag = true;
		}
		if (player.jump_flag) {
			player.y += player.jump;
			player.jump += 3;
		}
		if (player.y > DEFAULT_Y) {
			player.y = DEFAULT_Y;
			player.jump_flag = false;
		}
		//�E�ړ��i�A���[�L�[�E�j
		if (GetAsyncKeyState(VK_RIGHT)) {
			player.x += 2;

			//�ړ��͈͂̐���
			if (player.x > 60 - 2) {
				player.x = 60 - 2;
			}
		}
		//���ړ��i�A���[�L�[���j
		if (GetAsyncKeyState(VK_LEFT)) {
			player.x -= 2;

			//�ړ��͈͂̐���
			if (player.x < 0) {
				player.x = 0;
			}
		}

		//�J�[�\���ɑ��Ս��W�������ĕ`���h��Ԃ��ׂɍ��F�ɐݒ�
		pos.X = player.foot_markX;
		pos.Y = player.foot_markY;
		SetConsoleCursorPosition(hCons, pos);
		printf("�@");

		//�J�[�\���Ƀv���C���[���W�������ĕ`����u���v�ɐݒ�
		pos.X = player.x;
		pos.Y = player.y;
		SetConsoleCursorPosition(hCons, pos);
		printf("��");

		//����������������͂܂��I�I������������������������
		/*for (block_y = 0; block_y <= 6; block_y++)
		{
			for (block_x = 0; block_x <= 30; block_x++)
			{
				if (block_y == 0 && block_x == 0 || block_y == 0 && block_x == 30 || block_y == 6 && block_x == 0 || block_y == 6 && block_x == 30)
				{
					printf("��");
				}
				else if (block_y == 0 || block_y == 6)
				{
					printf("��");
				}
				else
				{
					printf("  ");
				}
			}
			printf("\n");
		}
		break;
		*/
		//�X�V�t���[��������u�T�O�v�ɐݒ�
		Sleep(50);
	}
}