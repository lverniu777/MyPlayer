package com.huaxia.huaxiaplayer

import android.media.MediaPlayer
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.huaxia.huaxiaplayer.databinding.ActivityMainBinding
import java.util.*

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val huaxiaPlayer = HuaXiaPlayer()
        huaxiaPlayer.setPlayUrl("")
        huaxiaPlayer.prepareAsync()
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = stringFromJNI()
    }

    /**
     * A native method that is implemented by the 'huaxiaplayer' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {
        // Used to load the 'huaxiaplayer' library on application startup.
        init {
            System.loadLibrary("huaxiaplayer")
        }
    }
}