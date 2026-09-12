# react-native-sound-api

Native audio controls for React Native using a TurboModule.

## Requirements

- React Native 0.76 or newer
- iOS 13 or newer
- Android API 24 or newer
- Node.js 22 or newer

## Installation

```sh
npm install react-native-sound-api
```

For iOS, install the CocoaPods dependencies after installing the package:

```sh
cd ios
pod install
```

Rebuild the application after installing the package. React Native autolinking registers the native module automatically.

## Usage

```ts
import {
  getDuration,
  getPosition,
  getState,
  load,
  pause,
  play,
  seek,
  stop,
} from 'react-native-sound-api';

load('move');
play();

pause();
seek(1000); // milliseconds
play();
stop();

const duration = getDuration(); // milliseconds
const position = getPosition(); // milliseconds
const state = getState();
```

## API

### `load(name: string): void`

Loads a named sound and resets its position to zero.

The Android engine currently recognizes these names:

- `move`
- `capture`
- `check`
- `castle`
- `game_end`
- `victory`

The corresponding files must be packaged as Android assets using the expected filenames, such as `move.mp3`.

### `play(): void`

Starts playback of the currently loaded sound.

### `pause(): void`

Pauses the current playback state.

### `stop(): void`

Stops playback and resets the position to zero.

### `seek(positionMilliseconds: number): void`

Moves the playback position in milliseconds. Values are clamped between zero and the loaded sound duration.

### `getDuration(): number`

Returns the loaded sound duration in milliseconds.

### `getPosition(): number`

Returns the current playback position in milliseconds.

### `getState(): string`

Returns the current state:

- `idle`
- `loaded`
- `playing`
- `paused`
- `stopped`

### `playSound(name: string): void`

Compatibility helper equivalent to `load(name)` followed by `play()`.

## Native implementation

The package uses React Native Codegen and a TurboModule named `NativeAudioModule`.

- Android uses the native media decoder and AAudio when available.
- Android API levels below 26 can decode assets but do not use AAudio playback.
- iOS is wired through the generated TurboModule provider. Platform audio playback implementation is still required for iOS.

## Development

Run the checks from the package root:

```sh
npm run typecheck
npm test -- --runInBand
```

Build the Android native target:

```sh
cd android
./gradlew ':app:buildCMakeDebug[x86_64]' -PreactNativeArchitectures=x86_64
```

Build the iOS workspace without code signing:

```sh
xcodebuild \
  -workspace ios/Audio.xcworkspace \
  -scheme Audio \
  -sdk iphonesimulator \
  -configuration Debug \
  CODE_SIGNING_ALLOWED=NO
```

## License

MIT
