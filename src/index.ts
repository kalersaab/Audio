import NativeAudioModule from '../specs/NativeAudioModule';

export {NativeAudioModule};

export const load = (name: string): void => NativeAudioModule.load(name);
export const play = (): void => NativeAudioModule.play();
export const pause = (): void => NativeAudioModule.pause();
export const stop = (): void => NativeAudioModule.stop();
export const seek = (positionMilliseconds: number): void =>
  NativeAudioModule.seek(positionMilliseconds);
export const getDuration = (): number => NativeAudioModule.getDuration();
export const getPosition = (): number => NativeAudioModule.getPosition();
export const getState = (): string => NativeAudioModule.getState();

export function playSound(name: string): void {
  NativeAudioModule.playSound(name);
}