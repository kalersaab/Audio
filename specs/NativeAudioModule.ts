import {TurboModule, TurboModuleRegistry} from 'react-native';

export interface Spec extends TurboModule {
  load(name: string): void;
  play(): void;
  pause(): void;
  stop(): void;
  seek(positionMilliseconds: number): void;
  getDuration(): number;
  getPosition(): number;
  getState(): string;
  playSound(name: string): void;
}

export default TurboModuleRegistry.getEnforcing<Spec>(
  'NativeAudioModule',
);