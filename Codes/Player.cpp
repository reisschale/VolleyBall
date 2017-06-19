//#include "Player.h"
//
////void Player::createPlayer() {
////	
////	//Schleife für zwei Spieler
////	for (int i = 0; i < 2; i++)
////	{
////		//Erstellt die Grundbox mit Koordinaten x= 20* i und y= 2
////		bdef.position.Set(20 * i, 2);
////
////		//Shapes für das Simulieren von Physikgesetzen und Aufprall mit anderen Objekten
////		//z.B: Ball mit Spieler, Spieler mit Spieler
////		b2CircleShape circle;
////		circle.m_radius = 32 / m_SCALEplayer;
////		circle.m_p.Set(0, 13 / m_SCALEplayer);
////
////
////		pBody[i] = World.CreateBody(&bdef);
////		pBody[i]->CreateFixture(&circle, 5);
////		circle.m_radius = 25 / m_SCALEplayer;
////		circle.m_p.Set(0, -20 / m_SCALEplayer);
////		pBody[i]->CreateFixture(&circle, 5);
////		pBody[i]->SetFixedRotation(true);
////	}
////	setScorePlayer1(16);
////	setScorePlayer2(2);
////}
//
//
////void Player::setPlayer() {
////	pBody[0]->SetUserData("player1");
////	pBody[1]->SetUserData("player2");
////}
//
///***Spieler_1************************************************/
//
//void Player::incrementScorePlayer1()
//{
//	m_scorePlayer1 = m_scorePlayer1++;
//};
//
//void Player::setScorePlayer1(int score)
//{
//	m_scorePlayer1 = score;
//};
///**************************************************************/
//
//
///***Spieler_2**************************************************/
//
//void Player::incrementScorePlayer2()
//{
//	m_scorePlayer2 = m_scorePlayer2++;
//};
//
//void Player::setScorePlayer2(int score)
//{
//	m_scorePlayer2 = score;
//};
///**************************************************************/
