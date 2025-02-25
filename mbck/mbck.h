#ifndef MBCK_H
#define MBCK_H

#include <stdlib.h>
#include <raylib.h>

// struct mbck_t, mbck_t : structure et type de structure voué a la mise en
//  place d'un fond parallax (fond qui ce mouvoit).
typedef struct mbck_t mbck_t;

//  init_mbck : Renvoie le controleur du fond parallax, b etant le chemin vers
//    l'image du fond, w et h la largeur et la hauteur déssirer. Le booléen
//    rotate est mise a disposition pour les images qui aurait besoin d'une
//    d'une rotation à 180° pour respecter la continuer du motif de l'image.
//    Renvoie nullptr en cas d'erreur, un pointeur sur la structure dans le cas
//    contraire.
extern mbck_t *init_mbck(const char *b, int w, int h, bool rotate);

//  dispose_mbck : Sans effet si *m vaut nullptr, libère la structure et les
//    donnés associé dans le cas contraire.
extern void dispose_mbck(mbck_t **m);

//  update_mbck_scale : Met a jour la taille désirer pour le fond parallax.
extern void update_mbck_scale(mbck_t *m, int width, int height);

//  mbck_physics_process : Fonction nécéssitant d'être appeler a chaque frame,
//    met a jour le fond parallax d'un mouvement de delta pixel.
extern void mbck_physics_process(mbck_t *m, float delta);

#endif
