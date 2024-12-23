/* Define lists for list of course for macros. Each of the following fields are described:
 * Argument 1: Course macro for define.
 * Argument 2: Star collection dance cutscenes
 * Each hex digit determines what dance cutscene to play for the stars in the course. The last digit is
 * unused. See determine_dance_cutscene() in camera.c for details.
 * Cutscene Digits:
 *      0: Lakitu flies away after the dance
 *      1: The camera rotates around mario
 *      2: The camera goes to a closeup of mario
 *      3: Bowser keys and the grand star
 *      4: Default, used for 100 coin stars, 8 red coin stars in bowser levels, and secret stars
 */
DEFINE_COURSE(COURSE_NONE, 0x44444440) // (0)  Course Hub (Castle Grounds)
DEFINE_COURSE(COURSE_CE, 0x44444440) 
DEFINE_COURSE(COURSE_WC, 0x44444440) 
DEFINE_COURSE(COURSE_PL, 0x44444440) 
DEFINE_COURSE(COURSE_MH, 0x44444440) 
DEFINE_COURSE(COURSE_GF, 0x44444440) 
DEFINE_COURSE(COURSE_PH, 0x44444440) 
DEFINE_COURSE(COURSE_MS, 0x44444440) 
DEFINE_COURSE(COURSE_AQ, 0x44444440) 
DEFINE_COURSES_END()
DEFINE_BONUS_COURSE(COURSE_CAKE_END, 0x44444440) // (25) The End (Cake Scene)