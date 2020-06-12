#include"CampoResultante.h"

CampoResultante::CampoResultante() {
	codigo = "CampoResultante";
	vec = new ContenedorV();
}
CampoResultante:: ~CampoResultante() {

}
string CampoResultante::getCodigo() {
	return codigo;
}
void CampoResultante::ingresaCampo(CampoAbstracto* obj) {
	vec->agregaCampo(obj);
}
ContenedorV* CampoResultante::retornaContenedor() {
	return vec;
}