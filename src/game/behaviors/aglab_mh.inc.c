void bhv_mh_music_loop()
{
    if (o->oDistanceToMario < 100.f)
    {
        seq_player_play_sequence(0, 0x34, 0);
        o->activeFlags = 0;
    }
}
