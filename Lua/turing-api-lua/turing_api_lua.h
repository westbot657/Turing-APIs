// Turing API - C/C++/Lua
// License: GPL-2.0-only
// Authors: Westbot
// <auto-converted from the rust api />

#ifndef WASM_IMPORTS_H
#define WASM_IMPORTS_H

#ifdef __cplusplus
extern "C" {
#endif

extern int _create_color_note(float beat);
extern void _beatmap_add_color_note(int color_note);
extern void _beatmap_remove_color_note(int color_note);
extern void _color_note_set_position(int color_note, int pos);
extern int _color_note_get_position(int color_note);
extern void _color_note_set_orientation(int color_note, int orientation);
extern int _color_note_get_orientation(int color_note);
extern void _color_note_set_color(int color_note, int color);
extern int _color_note_get_color(int color_note);
extern int _create_bomb_note(float beat);
extern void _beatmap_add_bomb_note(int bomb_note);
extern void _beatmap_remove_bomb_note(int bomb_note);
extern void _bomb_note_set_position(int bomb_note, int pos);
extern int _bomb_note_get_position(int bomb_note);
extern void _bomb_note_set_orientation(int bomb_note, int orientation);
extern int _bomb_note_get_orientation(int bomb_note);
extern void _bomb_note_set_color(int bomb_note, int color);
extern int _bomb_note_get_color(int bomb_note);
extern int _create_arc(float beat);
extern void _beatmap_add_arc(int arc);
extern void _beatmap_remove_arc(int arc);
extern void _arc_set_position(int arc, int pos);
extern int _arc_get_position(int arc);
extern void _arc_set_orientation(int arc, int orientation);
extern int _arc_get_orientation(int arc);
extern void _arc_set_color(int arc, int color);
extern int _arc_get_color(int arc);
extern int _create_wall(float beat);
extern void _beatmap_add_wall(int wall);
extern void _beatmap_remove_wall(int wall);
extern void _wall_set_position(int wall, int pos);
extern int _wall_get_position(int wall);
extern void _wall_set_orientation(int wall, int orientation);
extern int _wall_get_orientation(int wall);
extern void _wall_set_color(int wall, int color);
extern int _wall_get_color(int wall);
extern int _create_chain_head_note(float beat);
extern void _beatmap_add_chain_head_note(int chain_head_note);
extern void _beatmap_remove_chain_head_note(int chain_head_note);
extern void _chain_head_note_set_position(int chain_head_note, int pos);
extern int _chain_head_note_get_position(int chain_head_note);
extern void _chain_head_note_set_orientation(int chain_head_note, int orientation);
extern int _chain_head_note_get_orientation(int chain_head_note);
extern void _chain_head_note_set_color(int chain_head_note, int color);
extern int _chain_head_note_get_color(int chain_head_note);
extern int _create_chain_link_note(float beat);
extern void _beatmap_add_chain_link_note(int chain_link_note);
extern void _beatmap_remove_chain_link_note(int chain_link_note);
extern void _chain_link_note_set_position(int chain_link_note, int pos);
extern int _chain_link_note_get_position(int chain_link_note);
extern void _chain_link_note_set_orientation(int chain_link_note, int orientation);
extern int _chain_link_note_get_orientation(int chain_link_note);
extern void _chain_link_note_set_color(int chain_link_note, int color);
extern int _chain_link_note_get_color(int chain_link_note);
extern int _create_chain_note(float beat);
extern void _beatmap_add_chain_note(int chain_note);
extern void _beatmap_remove_chain_note(int chain_note);
extern void _chain_note_set_position(int chain_note, int pos);
extern int _chain_note_get_position(int chain_note);
extern void _chain_note_set_orientation(int chain_note, int orientation);
extern int _chain_note_get_orientation(int chain_note);
extern void _chain_note_set_color(int chain_note, int color);
extern int _chain_note_get_color(int chain_note);
extern void _saber_set_color(int saber, int color);
extern int _saber_get_color(int saber);
extern int _get_left_saber();
extern int _get_right_saber();
extern void _log(const char* message);
extern void _drop_reference(void* ptr);
extern int _vec2_from_native(float x, float y);
extern int _vec3_from_native(float x, float y, float z);
extern int _vec4_from_native(float x, float y, float z, float w);
extern int _quat_from_native(float x, float y, float z, float w);
extern void _color_set_rgb(int color, float r, float g, float b);
extern void _color_set_rgba(int color, float r, float g, float b, float a);
extern float _vec2_get_x(int vec2);
extern void _vec2_set_x(int vec2, float x);
extern float _vec2_get_y(int vec2);
extern void _vec2_set_y(int vec2, float y);
extern float _vec3_get_x(int vec3);
extern void _vec3_set_x(int vec3, float x);
extern float _vec3_get_y(int vec3);
extern void _vec3_set_y(int vec3, float y);
extern float _vec3_get_z(int vec3);
extern void _vec3_set_z(int vec3, float z);
extern float _vec4_get_x(int vec4);
extern void _vec4_set_x(int vec4, float x);
extern float _vec4_get_y(int vec4);
extern void _vec4_set_y(int vec4, float y);
extern float _vec4_get_z(int vec4);
extern void _vec4_set_z(int vec4, float z);
extern float _vec4_get_w(int vec4);
extern void _vec4_set_w(int vec4, float w);
extern float _quat_get_x(int quat);
extern void _quat_set_x(int quat, float x);
extern float _quat_get_y(int quat);
extern void _quat_set_y(int quat, float y);
extern float _quat_get_z(int quat);
extern void _quat_set_z(int quat, float z);
extern float _quat_get_w(int quat);
extern void _quat_set_w(int quat, float w);
extern float _color_get_r(int color);
extern void _color_set_r(int color, float r);
extern float _color_get_g(int color);
extern void _color_set_g(int color, float g);
extern float _color_get_b(int color);
extern void _color_set_b(int color, float b);
extern float _color_get_a(int color);
extern void _color_set_a(int color, float a);

#ifdef __cplusplus
}
#endif

#endif // WASM_IMPORTS_H