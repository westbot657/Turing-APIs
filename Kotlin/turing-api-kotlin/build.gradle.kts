plugins {
    kotlin("multiplatform") version "2.0.0"
}

kotlin {
    wasmWasi {
        compilations["main"].cinterops {
            create("turingapi") {
                defFile = file("src/main/c_interop/turingapi.def")
                includeDirs("$projectDir/include", "$projectDir/../../turing-api-c/include")
            }
        }

        binaries {
            staticLib() // build as a static library (.klib)
        }
    }

    sourceSets {
        val wasmWasiMain by getting {
            kotlin.srcDir("src/main/kotlin")
        }
    }
}
